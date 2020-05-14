#include <iostream>

using namespace std;

#define MOD (int)1e9

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int dp[101][10] = { 0, };
    for (int i = 0; i <= 9; ++i)
        dp[1][i] = 1;
    for (int i = 2; i <= N; ++i)
    {
        dp[i][0] = dp[i - 1][1] % MOD;
        for (int j = 1; j < 9; ++j)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        dp[i][9] = dp[i - 1][8] % MOD;
    }
    int cnt = 0;
    for (int i = 1; i <= 9; ++i)
    {
        cnt += dp[N][i];
        cnt %= MOD;
    }
    cout << cnt;
    
    return 0;
}