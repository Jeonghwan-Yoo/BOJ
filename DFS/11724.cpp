#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1'001];
bool visited[1'001];

void Dfs(int src)
{
    visited[src] = true;
    for (int i = 0; i < adj[src].size(); ++i)
    {
        if (visited[adj[src][i]] == true)
            continue;
        Dfs(adj[src][i]);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (visited[i] == true)
            continue;
        ++cnt;
        Dfs(i);
    }
    cout << cnt;
    return 0;
}