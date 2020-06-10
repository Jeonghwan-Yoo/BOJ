#include <iostream>

using namespace std;

#define INF 501

int N, M;
int adj[501][501];
int dist[501][501];

void FloydWarshall()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            dist[i][j] = adj[i][j];

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (dist[i][k] == 1 && dist[k][j] == 1)
                    dist[i][j] = 1;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        adj[a][b] = 1;
    }
    FloydWarshall();
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        int visited = 0;
        for (int j = 1; j <= N; ++j)
            if (dist[i][j] == 1)
                ++visited;
        for (int j = 1; j <= N; ++j)
            if (dist[j][i] == 1)
                ++visited;
        if (visited == N - 1)
            ++cnt;
    }
    cout << cnt;

    return 0;
}