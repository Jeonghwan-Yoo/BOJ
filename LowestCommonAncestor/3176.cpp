#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100'001
#define LOG2MAX (int)(log2(MAX) + 1)
#define INF 1'000'000

int N;
vector<pair<int, int> > adj[MAX];
int visited[MAX];
int depth[MAX];
int parent[LOG2MAX][MAX];
int distMin[LOG2MAX][MAX];
int distMax[LOG2MAX][MAX];

void Dfs(int src, int d)
{
    visited[src] = true;
    depth[src] = d;
    for (auto &a : adj[src])
    {
        if (visited[a.first] == true)
            continue;
        parent[0][a.first] = src;
        distMin[0][a.first] = a.second;
        distMax[0][a.first] = a.second;
        Dfs(a.first, d + 1);
    }
}

void BuildSparseTable()
{
    for (int i = 1; i < LOG2MAX; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
            distMin[i][j] = min(distMin[i - 1][j], distMin[i - 1][parent[i - 1][j]]);
            distMax[i][j] = max(distMax[i - 1][j], distMax[i - 1][parent[i - 1][j]]);
        }
    }
}

pair<int, int> DistMinMax(int a, int b)
{
    int minVal = INF;
    int maxVal = 0;
    if (depth[a] > depth[b])
        swap(a, b);

    for (int i = LOG2MAX - 1; i >= 0; --i)
    {
        if (depth[b] - depth[a] >= (1 << i))
        {
            minVal = min(minVal, distMin[i][b]);
            maxVal = max(maxVal, distMax[i][b]);
            b = parent[i][b];
        }
    }

    if (a == b)
        return { minVal, maxVal };

    for (int i = LOG2MAX - 1; i >= 0; --i)
    {
        if (parent[i][a] != parent[i][b])
        {
            minVal = min({ minVal, distMin[i][a], distMin[i][b] });
            maxVal = max({ maxVal, distMax[i][a], distMax[i][b] });
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    minVal = min({ minVal, distMin[0][a], distMin[0][b] });
    maxVal = max({ maxVal, distMax[0][a], distMax[0][b] });
    
    return { minVal, maxVal };
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }
    Dfs(1, 0);
    BuildSparseTable();

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> ret = DistMinMax(a, b);
        cout << ret.first << ' ' << ret.second << '\n';
    }
    
    return 0;
}