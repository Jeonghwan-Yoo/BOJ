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
    sort(coin, coin + n);
    int dp[10001] = { 1, };
    for (int i = 0; i < n; ++i)
        for (int j = coin[i]; j <= k; ++j)
            if (j - coin[i] >= 0)
                dp[j] += dp[j - coin[i]];
    cout << dp[k];

    return 0;
}