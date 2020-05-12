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
    int dp[1'001] = { 0, };
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; ++i)
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    cout << dp[N];
    return 0; 
}