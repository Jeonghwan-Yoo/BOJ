#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1e9

vector<pair<int, int> > adj[1001];

int Prim(int V)
{
    int src = 0;
    int totalCost = 0;
    vector<int> cost(V, INF);
    vector<int> visited(V, 0);
    priority_queue<pair<int, int> > pq;
    pq.push({ 0, src });
    while (pq.empty() == false)
    {
        pair<int, int> edge = pq.top();
        int a = -edge.second;
        int c = -edge.first;
        pq.pop();
        if (visited[a] == true)
            continue;
        visited[a] = true;
        totalCost += c;
        for (auto &u : adj[a])
        {
            int b = u.first;
            int w = u.second;
            if (cost[b] > w)
                pq.push({ -w, -b });
        }
    }
    return totalCost;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }
    int totalCost = Prim(N);
    cout << totalCost;

    return 0;
}