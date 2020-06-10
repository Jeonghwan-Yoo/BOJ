#include <iostream>
#include <algorithm>

using namespace std;

#define INF 100'001 * 100

int N, M;
int adj[101][101];
int dist[101][101];

void FloydWarshall()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            dist[i][j] = adj[i][j];

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            adj[i][j] = INF;

    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
    FloydWarshall();
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (dist[i][j] >= INF || i == j)
                dist[i][j] = 0;
            cout << dist[i][j] << ' '; 
        }
        cout << '\n';
    }

    return 0;
}