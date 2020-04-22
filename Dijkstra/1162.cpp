#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 1e18

struct Graph
{
    long long weight;
    int from;
    int pavement;
    
    bool operator<(const Graph& a) const
    {
        return (weight > a.weight);
    }
};

vector<pair<int, int> > adj[10001];
long long time[10001][21];
priority_queue<Graph> pq;

void Dijkstra(int src, int V, int K)
{
    for (int i = 1; i <= V; ++i)
    {
        for (int j = 0; j <= K; ++j)
        {
            time[i][j] = INF;
        }
    }
    time[src][0] = 0;
    pq.push({ 0, src, 0 });
    while (!pq.empty())
    {
        int a = pq.top().from;
        long long w = pq.top().weight;
        int k = pq.top().pavement;
        pq.pop();
        if (w > time[a][k])
            continue;
        for (auto &u : adj[a])
        {
            int to = u.first;
            long long nw = u.second;
            if (w + nw < time[to][k])
            {
                time[to][k] = w + nw;
                pq.push({ time[to][k], to, k });
            }
            if (k < K && w < time[to][k + 1])
            {
                time[to][k + 1] = w;
                pq.push({ time[to][k + 1], to, k + 1 });
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({ to, weight });
        adj[to].push_back({ from, weight });
    }
    Dijkstra(1, N, K);
    cout << time[N][K];
    
    return 0;
}