#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    if (K != 0)
        --K;
    int r = K / M;
    int c = K % M;
    vector<vector<int>> dp(N, vector<int>(M));
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[r][c] * dp[N - 1 - r][M - 1 - c];

    return 0;
}