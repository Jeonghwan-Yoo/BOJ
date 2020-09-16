#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> adj[1'001];
bool visited[1'001];

void Dfs(int src)
{
    visited[src] = true;
    cout << src << ' ';
    for (auto &a : adj[src])
        if (!visited[a])
            Dfs(a);
}

void Bfs(int src)
{
    queue<int> q;
    visited[src] = true;
    q.emplace(src);
    while (!q.empty())
    {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for (auto &a : adj[cur])
        {
            if (!visited[a])
            {
                visited[a] = true;
                q.emplace(a);
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> V;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for (int i = 1; i <= N; ++i)
        sort(adj[i].begin(), adj[i].end());

    Dfs(V);
    for (int i = 1; i <= N; ++i)
        visited[i] = false;
    cout << '\n';
    Bfs(V);

    return 0;
}