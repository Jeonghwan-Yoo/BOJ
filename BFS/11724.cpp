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
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    vector<int> visited(N + 1);
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            ++cnt;
            queue<int> q;
            visited[i] = 1;
            q.emplace(i); 
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                
                for (auto &g : graph[cur])
                {
                    if (!visited[g])
                    {
                        visited[g] = 1;
                        q.emplace(g);
                    }
                }
            }
        }
    }
    cout << cnt;

    return 0;
}