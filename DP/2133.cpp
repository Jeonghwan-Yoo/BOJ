#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt" ,"r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int dp[2][31] = { 0, };
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        dp[0][i] = dp[0][i - 2] + (dp[1][i - 1] << 1);
        dp[1][i] = dp[0][i - 1] + dp[1][i - 2];
    }
    cout << dp[0][N];

    return 0;
}