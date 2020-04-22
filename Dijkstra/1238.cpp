#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1e9

vector<pair<int, int> > adj[1001][2];
int tmpTime[1001];
int time[1001];
bool visited[1001];

void Dijkstra(int src, int N, int order)
{
    for (int i = 1; i <= N; ++i)
    {
        tmpTime[i] = INF;
        visited[i] = false;
    }
    tmpTime[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push({ 0, src });
    while (!pq.empty())
    {
        int a = pq.top().second;
        pq.pop();
        if (visited[a] == true)
            continue;
        visited[a] = true;
        for (auto &e : adj[a][order])
        {
            int b = e.first;
            int w = e.second;
            if (tmpTime[a] + w < tmpTime[b])
            {
                tmpTime[b] = tmpTime[a] + w;
                pq.push({ -tmpTime[b], b });
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, X;
    cin >> N >> M >> X;
    for (int i = 0; i < M; ++i)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a][0].push_back({ b, t });
        adj[b][1].push_back({ a, t });
    }
    Dijkstra(X, N, 0);
    for (int i = 1; i <= N; ++i)
    {
        if (i == X)
            continue;
        time[i] = tmpTime[i];
    }
    Dijkstra(X, N, 1);
    int maxTime = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (i == X)
            continue;
        time[i] += tmpTime[i];
        if (time[i] > maxTime)
            maxTime = time[i];
    }
    cout << maxTime;
    return 0;
}