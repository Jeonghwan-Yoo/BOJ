#include <iostream>

using namespace std;

#define MOD 9'901

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dp[3][2] = { 0, };
    int N;
    cin >> N;
    dp[0][1] = 1;
    dp[1][1] = 1;
    dp[2][1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        dp[0][i & 1] = (dp[1][(i - 1) & 1] + dp[2][(i - 1) & 1]) % MOD;
        dp[1][i & 1] = (dp[0][(i - 1) & 1] + dp[2][(i - 1) & 1]) % MOD;
        dp[2][i & 1] = (dp[0][(i - 1) & 1] + dp[1][(i - 1) & 1] + dp[2][(i - 1) & 1]) % MOD;
    }
    cout << (dp[0][N & 1] + dp[1][N & 1] + dp[2][N & 1]) % MOD;

    return 0;
}