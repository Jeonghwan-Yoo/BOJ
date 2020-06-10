#include <iostream>

using namespace std;

int adj[101][101];
int dist[101][101];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
    }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            dist[i][j] = adj[i][j];

    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (dist[i][k] == 1 && dist[k][j] == 1)
                    dist[i][j] = 1;
    
    for (int i = 1; i <= N; ++i)
    {
        int visited = 0;
        for (int j = 1; j <= N; ++j)
            if (dist[i][j] == 1)
                ++visited;
        for (int j = 1; j <= N; ++j)
            if (dist[j][i] == 1)
                ++visited;
        cout << N - 1 - visited << '\n';
    }
                    
    return 0;
}