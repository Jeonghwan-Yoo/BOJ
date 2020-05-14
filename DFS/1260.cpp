#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> edge[1'001];
int visited[1'001];

void Dfs(int src)
{
    visited[src] = true;
    cout << src << ' ';
    for (int i = 0; i < edge[src].size(); ++i)
    {
        if (visited[edge[src][i]] == true)
            continue;
        Dfs(edge[src][i]);
    }
}

void Bfs(int V)
{
    queue<int> q;
    q.push(V);
    visited[V] = true;
    while (!q.empty())
    {
        int src = q.front();
        q.pop();
        cout << src << ' ';
        for (int i = 0; i < edge[src].size(); ++i)
        {
            if (visited[edge[src][i]] == true)
                continue;
            visited[edge[src][i]] = true;
            q.push(edge[src][i]);
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
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i)
        sort(edge[i].begin(), edge[i].end());
    Dfs(V);
    cout << '\n';
    memset(visited, 0, sizeof(visited));
    Bfs(V);
    return 0;
}