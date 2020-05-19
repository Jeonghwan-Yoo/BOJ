#include <iostream>

using namespace std;

#define MOD (int)(1e4 + 7)

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int dp[10] = { 0, };
    dp[0] = 1;
    for (int i = 0; i <= N; ++i)
        for (int j = 1; j < 10; ++j)
            dp[j] = (dp[j] + dp[j - 1]) % MOD;

    cout << dp[9];

    return 0;
}