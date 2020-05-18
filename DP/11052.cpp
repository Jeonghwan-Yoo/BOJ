#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int card[1'001] = { 0, };
    int dp[1'001] = { 0, };
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> card[i];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (i - j >= 0)
                dp[i] = max(dp[i], dp[i - j] + card[j]);

    cout << dp[N];

    return 0;
}