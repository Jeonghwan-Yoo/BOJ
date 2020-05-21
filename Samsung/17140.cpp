#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1000

int r, c, k;
int board[101][101];
int rMax;
int cMax;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> r >> c >> k;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> board[i][j];
    rMax = 3;
    cMax = 3;

    int t = 0;
    while (t <= 100)
    {
        if (board[r - 1][c - 1] == k)
            break;

        if (rMax >= cMax)
        {
            int tmpMax = 0;
            for (int i = 0; i < rMax; ++i)
            {
                pair<int, int> cntMap[101];
                for (int j = 0; j < cMax; ++j)
                {
                    cntMap[board[i][j]].first = board[i][j];
                    ++cntMap[board[i][j]].second;
                    board[i][j] = 0;
                }
                for (int j = 0; j < 101; ++j)
                    if (cntMap[j].second == 0 || cntMap[j].first == 0)
                        cntMap[j].second = INF;
                sort(cntMap, cntMap + 101, [&cntMap](const pair<int, int> &a, const pair<int, int> &b)
                {
                    if (a.second == b.second)
                        return a.first < b.first;
                    return a.second < b.second;
                });
                for (int j = 0; j < 50; ++j)
                {
                    if (cntMap[j].second == INF)
                    {
                        tmpMax = max(tmpMax, j << 1);
                        break;
                    }
                    board[i][j << 1] = cntMap[j].first;
                    board[i][(j << 1) + 1] = cntMap[j].second;
                }
            }
            cMax = tmpMax;
        }
        else
        {
            int tmpMax = 0;
            for (int i = 0; i < cMax; ++i)
            {
                pair<int, int> cntMap[101];
                for (int j = 0; j < rMax; ++j)
                {
                    cntMap[board[j][i]].first = board[j][i];
                    ++cntMap[board[j][i]].second;
                    board[j][i] = 0;
                }
                for (int j = 0; j < 101; ++j)
                    if (cntMap[j].second == 0 || cntMap[j].first == 0)
                        cntMap[j].second = INF;
                sort(cntMap, cntMap + 101, [&cntMap](const pair<int, int> &a, const pair<int, int> &b)
                {
                    if (a.second == b.second)
                        return a.first < b.first;
                    return a.second < b.second;
                });
                for (int j = 0; j < 50; ++j)
                {
                    if (cntMap[j].second == INF)
                    {
                        tmpMax = max(tmpMax, j << 1);
                        break;
                    }
                    board[j << 1][i] = cntMap[j].first;
                    board[(j << 1) + 1][i] = cntMap[j].second;
                }
            }
            rMax = tmpMax;
        }
        ++t;
    }
    if (board[r - 1][c - 1] != k)
        t = -1;

    cout << t;

    return 0;
}