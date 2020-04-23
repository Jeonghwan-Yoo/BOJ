#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9

int N, M;
int relationship[101][101];
int dist[101][101];

void FloydWarshall()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (relationship[i][j] == 0)
            {
                relationship[i][j] = INF;
            }
            dist[i][j] = relationship[i][j];
        }
    }

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        relationship[from][to] = 1;
        relationship[to][from] = 1;
    }
    FloydWarshall();
    int minCnt = INF;
    int minIdx = -1;
    for (int i = 1; i <= N; ++i)
    {
        int sum = 0;
        for (int j = 1; j <= N; ++j)
        {
            sum += dist[i][j];
        }
        if (sum < minCnt)
        {
            minCnt = sum;
            minIdx = i;
        }
    }
    cout << minIdx;

    return 0;
}