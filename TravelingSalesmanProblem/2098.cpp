#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (int)1e9

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                board[i][j] = INF;
        }
    }

    vector<vector<int>> dp(1 << N, vector<int>(N, INF));
    dp[1][0] = 0;
    for (int i = 1; i < (1 << N); ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i & (1 << j))
            {
                for (int k = 0; k < N; ++k)
                {
                    if (j == k)
                        continue;
                    dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + board[k][j]);
                }
            }
        }
    }
    int minDist = INF;
    for (int i = 0; i < N; ++i)
        minDist = min(minDist, dp[(1 << N) - 1][i] + board[i][0]);
    cout << minDist;

    return 0;
}