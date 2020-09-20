#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<int> adj[101];
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vector<int> visited(N);
    queue<int> q;
    visited[1] = 1;
    q.emplace(1);
    int cnt = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto &a : adj[cur])
        {
            if (!visited[a])
            {
                visited[a] = 1;
                q.emplace(a);
                ++cnt;
            }
        }
    }
    cout << cnt;

    return 0;
}