#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

int graph[51][51];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        char in;
        for (int j = 0; j < N; ++j)
        {
            cin >> in;
            graph[i][j] = (in == 'Y' ? 1 : INF);
        }
    }

    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (i == j)
                    continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    int maxCnt = 0;
    for (int i = 0; i < N; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < N; ++j)
        {
            if (graph[i][j] <= 2)
                ++cnt;
        }
        if (cnt > maxCnt)
            maxCnt = cnt;
    }
    cout << maxCnt;

    return 0;
}