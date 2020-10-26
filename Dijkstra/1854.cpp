#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF (int)1e6

int n, m, k;

void Dijkstra(int src, vector<priority_queue<int>> &dp, vector<vector<pair<int, int>>> const &adj)
{
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);
    dp[src].emplace(0);
    while (!pq.empty())
    {
        int a = pq.top().second;
        int pw = -pq.top().first;
        pq.pop();
        if (dp[a].top() < pw)
            continue;
        for (auto &u : adj[a])
        {
            int b = u.first;
            int w = u.second;
            int nw = w + pw;
            if ((int)dp[b].size() < k)
            {
                dp[b].emplace(nw);
                pq.emplace(-nw, b);
            }
            else if (dp[b].top() > nw)
            {
                dp[b].pop();
                dp[b].emplace(nw);
                pq.emplace(-nw, b);
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
    }
    vector<priority_queue<int>> dp(n + 1);
    Dijkstra(1, dp, adj);
    for (int i = 1; i <= n; ++i)
    {
        if ((int)dp[i].size() < k)
            cout << -1 << '\n';
        else
            cout << dp[i].top() << '\n';
    }

    return 0;
}