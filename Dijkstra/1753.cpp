#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF (int)1e6

int V, E;
vector<pair<int, int> > adj[20'001];
int dp[20'001];
bool visited[20'001];

void Dijkstra(int src)
{
    for (int i = 1; i <= V; ++i)
        dp[i] = INF;
    dp[src] = 0;

    priority_queue<pair<int, int> > pq;
    pq.emplace(0, src);
    while (!pq.empty())
    {
        int here = pq.top().second;
        pq.pop();
        if (visited[here] == true)
            continue;
        visited[here] = true;
        for (auto &a : adj[here])
        {
            int there = a.first;
            int weight = a.second;
            if (dp[here] + weight < dp[there])
            {
                dp[there] = dp[here] + weight;
                pq.emplace(-dp[there], there);
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> V >> E;
    int K;
    cin >> K;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    Dijkstra(K);
    for (int i = 1; i <= V; ++i)
    {
        if (dp[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dp[i] << '\n';
    }

    return 0;
}