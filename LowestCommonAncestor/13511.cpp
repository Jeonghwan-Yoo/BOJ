#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100'001
#define LOG2MAX (int)(log2(MAX) + 1)

int N;
vector<pair<int, int> > adj[MAX];
int depth[MAX];
int parent[LOG2MAX][MAX];
long long sumDist[MAX];
bool visited[MAX];

void Dfs(int src, int d)
{
    visited[src] = true;
    depth[src] = d;
    for (auto &a : adj[src])
    {
        if (visited[a.first] == true)
            continue;
        sumDist[a.first] = sumDist[src] + a.second;
        parent[0][a.first] = src;
        Dfs(a.first, d + 1);
    }
}

void BuildSparseTable()
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
            b = parent[i][b];
            a = parent[i][a];
        }
    }
    return parent[0][a];
}

long long Dist(int a, int b)
{
    int lca = Lca(a, b);
    return sumDist[a] - sumDist[lca] + sumDist[b] - sumDist[lca];
}

int Vertex(int a, int b, int k)
{
    int lca = Lca(a, b);
    int diff = depth[a] - depth[lca];
    int v = 0;
    if (k <= diff + 1)
    {
        int cnt = k - 1;
        for (int i = LOG2MAX - 1; i >= 0; --i)
        {
            if (cnt >= (1 << i))
            {
                cnt -= (1 << i);
                a = parent[i][a];
            }
        }
        v = a;
    }
    else
    {
        int cnt = diff + depth[b] - depth[lca] - k + 1;
        for (int i = LOG2MAX - 1; i >= 0; --i)
        {
            if (cnt >= (1 << i))
            {
                cnt -= (1 << i);
                b = parent[i][b];
            }
        }
        v = b;
    }
    return v;
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
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    Dfs(1, 0);
    BuildSparseTable();

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int u, v; 
            cin >> u >> v;
            cout << Dist(u, v) << '\n';
        }
        else if (a == 2)
        {
            int u, v, k;
            cin >> u >> v >> k;
            cout << Vertex(u, v, k) << '\n';
        }
    }

    return 0;
}