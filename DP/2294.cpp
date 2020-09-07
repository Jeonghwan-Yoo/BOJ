#include <iostream>
#include <algorithm>

using namespace std;

#define INF 10'001

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int coin[101];
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> coin[i];

    int dp[10'001] = { 0, };
    for (int i = 1; i <= k; ++i)
        dp[i] = INF;
    for (int i = 0; i < n; ++i)
        for (int j = coin[i]; j <= k; ++j)
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
            
    int minVal = dp[k];
    if (dp[k] == INF)
        minVal = -1;
    cout << minVal;

    return 0;
}