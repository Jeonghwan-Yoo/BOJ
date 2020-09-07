#include <iostream>

using namespace std;

#define MOD (int)(1e4 + 7)

int dp[2][1'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[1'001];
    int N, K;
    cin >> N >> K;

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j <= K; ++j)
        {
            if (j == 0)
                dp[i & 1][j] = dp[(i - 1) & 1][j];
            else
                dp[i & 1][j] = dp[(i - 1) & 1][j] + dp[(i - 1) & 1][j - 1];
            if (dp[i & 1][j] >= MOD)
                dp[i & 1][j] -= MOD;
        }
    }

    cout << dp[N & 1][K];

    return 0;
}