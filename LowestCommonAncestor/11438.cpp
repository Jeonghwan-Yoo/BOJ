#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100'001
#define LOG2MAX (int)(log2(MAX) + 1)

int N;
vector<int> adj[MAX];
int parent[LOG2MAX][MAX];
bool visited[MAX];
int depth[MAX];

void Dfs(int src, int d)
{
    visited[src] = true;
    depth[src] = d;
    for (auto &a : adj[src])
    {
        if (visited[a] == true)
            continue;
        parent[0][a] = src;
        Dfs(a, d + 1);
    }
}

void SparseTable()
{
    for (int i = 1; i < LOG2MAX; ++i)
        for (int j = 1; j <= N; ++j)
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
}

int Lca(int a, int b)
{
    if (depth[a] > depth[b])
        swap(a, b);
    
    for (int i = LOG2MAX - 1; i >= 0; --i)
        if (depth[b] - depth[a] >= (1 << i))
            b = parent[i][b];

    if (a == b)
        return a;
    
    for (int i = LOG2MAX - 1; i >= 0; --i)
    {
        if (parent[i][a] != parent[i][b])
        {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Dfs(1, 0);
    SparseTable();

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << Lca(a, b) << '\n';
    }
    return 0;
}
