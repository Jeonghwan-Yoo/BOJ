#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF (int)1e9

int n, m;

void Dijkstra(int src, int dst, vector<int> &dp, vector<int> &path, vector<vector<pair<int, int>>> const &adj)
{
    vector<int> parent(n + 1);
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);
    dp[src] = 0;
    while (!pq.empty())
    {
        int a = pq.top().second;
        pq.pop();
        if (a == dst)
            break;
        for (auto &u : adj[a])
        {
            int b = u.first;
            int w = u.second;
            int nw = w + dp[a];
            if (dp[b] > nw)
            {
                dp[b] = nw;
                pq.emplace(-nw, b);
                parent[b] = a;
            }
        }
    }
    int cur = dst;
    while (cur)
    {
        path.emplace_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
    }
    int s, e;
    cin >> s >> e;
    vector<int> dp(n + 1, INF);
    vector<int> path;
    Dijkstra(s, e, dp, path, adj);
    cout << dp[e] << '\n' << (int)path.size() << '\n';
    for (int i = 0; i < (int)path.size(); ++i)
        cout << path[i] << ' ';

    return 0;
}