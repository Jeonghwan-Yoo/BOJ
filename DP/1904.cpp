#include <iostream>

using namespace std;

#define MOD 15746

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int dp[3] = { 0, };
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 0; i < N; ++i)
    {
        dp[2] = dp[0] + dp[1];
        if (dp[2] >= MOD)
            dp[2] -= MOD;
        dp[0] = dp[1];
        dp[1] = dp[2];
    }
    cout << dp[2];

    return 0;
}