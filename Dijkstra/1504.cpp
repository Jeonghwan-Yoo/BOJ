#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF (int)8e6

int N, E;

void Dijkstra(int src, vector<int> &dp, vector<vector<pair<int, int>>> const &adj)
{
    vector<int> visited(N + 1);
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);
    dp[src] = 0;
    while (!pq.empty())
    {
        int a = pq.top().second;
        pq.pop();

        if (visited[a])
            continue;
        visited[a] = 1;

        for (auto &u : adj[a])
        {
            int b = u.first;
            int w = u.second;
            if (dp[b] > dp[a] + w)
            {
                dp[b] = dp[a] + w;
                pq.emplace(-dp[b], b);
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    int v1, v2;
    cin >> v1 >> v2;
    vector<int> dp1(N + 1, INF);
    vector<int> dp2(N + 1, INF);
    Dijkstra(v1, dp1, adj);
    Dijkstra(v2, dp2, adj);
    int dist1 = dp1[1] + dp1[v2] + dp2[N];
    int dist2 = dp2[1] + dp2[v1] + dp1[N];
    int dist = min(dist1, dist2);
    if (dist >= INF)
        dist = -1;
    cout << dist;

    return 0;
}