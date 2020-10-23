#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF (int)1e9

int N, M;
void Dijkstra(vector<vector<pair<int, int>>> const &adj, vector<int> &dp, int s)
{
    vector<int> visited(N + 1);
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, s);
    dp[s] = 0;
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
            if (dp[a] + w < dp[b])
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

    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
    }
    int s, e;
    cin >> s >> e;
    vector<int> dp(N + 1, INF);
    Dijkstra(adj, dp, s);
    cout << dp[e];

    return 0;
}