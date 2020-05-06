#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int coin[101] = { 0, };
    for (int i = 0; i < n; ++i)
        cin >> coin[i];
    int dp[2][10001] = { 0, };
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            if (j - coin[i] >= 0)
                dp[i & 1][j] = dp[i & 1][j - coin[i]] + dp[(i - 1) & 1][j];
            else
                dp[i & 1][j] = dp[(i - 1) & 1][j];
        }
    }
    cout << dp[(n - 1) & 1][k];

    return 0;
}
