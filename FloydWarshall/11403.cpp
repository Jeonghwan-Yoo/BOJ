#include <iostream>

using namespace std;

int adj[101][101];
int dist[101][101];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> adj[i][j];
            dist[i][j] = adj[i][j];
        }
    }

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dist[i][j] |= dist[i][k] && dist[k][j];
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << dist[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}