#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

#define INF 1e6

double Dist(pair<int, int> const &a, pair<int, int> const &b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int N;
    cin >> N;
    vector<pair<int, int>> xy(N);
    for (int i = 0; i < N; ++i)
        cin >> xy[i].first >> xy[i].second;
    
    vector<vector<double>> board(N, vector<double>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = Dist(xy[i], xy[j]);

    vector<vector<double>> dp(1 << N, vector<double>(N, INF));
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
    double minDist = INF;
    for (int i = 0; i < N; ++i)
        minDist = min(minDist, dp[(1 << N) - 1][i] + board[i][0]);
    cout << fixed << setprecision(6) << minDist;

    return 0;
}