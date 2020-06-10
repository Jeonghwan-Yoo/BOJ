#include <iostream>

using namespace std;

int adj[401][401];
int dist[401][401];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int a, b;
    for (int i = 0; i < K; ++i)
    {
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

    int S;
    cin >> S;
    for (int i = 0; i < S; ++i)
    {
        cin >> a >> b;
        if (dist[a][b] == 1)
            cout << -1 << '\n';
        else if (dist[b][a] == 1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}