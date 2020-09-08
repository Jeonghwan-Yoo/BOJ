#include <iostream>

using namespace std;

#define MOD (int)(1e9)

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dp[201] = { 0, };
    int N, K;
    cin >> N >> K;
    dp[1] = 1;
    for (int i = 0; i <= N; ++i)
        for (int j = 2; j <= K; ++j)
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
            
    cout << dp[K];

    return 0;
}