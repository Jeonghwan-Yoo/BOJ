#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 100'001 * 100

int adj[101][101];
int dist[101][101];
int pass[101][101];
vector<int> path[101][101];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            adj[i][j] = INF;
            pass[i][j] = j;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (adj[a][b] > 0)
            adj[a][b] = min(adj[a][b], c);
        else
            adj[a][b] = c;
    }

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            dist[i][j] = adj[i][j];

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (i == j)
                    continue;
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pass[i][j] = pass[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (dist[i][j] >= INF)
                cout << 0 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (dist[i][j] < INF)
            {
                int cur = i;
                path[i][j].emplace_back(i);
                while (pass[cur][j] != j)
                {
                    cur = pass[cur][j];
                    path[i][j].emplace_back(cur);
                }
                path[i][j].emplace_back(j);
            }
            cout << (int)path[i][j].size() << ' ';
            for (auto &p : path[i][j])
                cout << p << ' ';
            cout << '\n';
        }
    }
    
    return 0;
}