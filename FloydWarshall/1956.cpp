#include <iostream>
#include <algorithm>

using namespace std;

#define INF 10'001 * 400

int adj[401][401];
int dist[401][401];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;
    for (int i = 1; i <= V; ++i)
        for (int j = 1; j <= V; ++j)
            adj[i][j] = INF;
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    for (int i = 1; i <= V; ++i)
        for (int j = 1; j <= V; ++j)
            dist[i][j] = adj[i][j];
    
    for (int k = 1; k <= V; ++k)
        for (int i = 1; i <= V; ++i)
            for (int j = 1; j <= V; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            
    int minDist = INF;
    for (int i = 1; i <= V; ++i)
        minDist = min(minDist, dist[i][i]);
    if (minDist == INF)
        minDist = -1;
    cout << minDist;

    return 0;
}