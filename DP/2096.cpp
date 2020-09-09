#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][2][3];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int cur = i & 1;
        int prev = (i - 1) & 1;
        cin >> dp[cur][0][0] >> dp[cur][0][1] >> dp[cur][0][2];
        dp[cur][1][0] = dp[cur][0][0];
        dp[cur][1][1] = dp[cur][0][1];
        dp[cur][1][2] = dp[cur][0][2];
        dp[cur][0][0] += max(dp[prev][0][0], dp[prev][0][1]);
        dp[cur][0][2] += max(dp[prev][0][1], dp[prev][0][2]);
        dp[cur][0][1] += max({ dp[prev][0][0], dp[prev][0][1], dp[prev][0][2] });
        dp[cur][1][0] += min(dp[prev][1][0], dp[prev][1][1]);
        dp[cur][1][1] += min({ dp[prev][1][0], dp[prev][1][1], dp[prev][1][2] });
        dp[cur][1][2] += min(dp[prev][1][1], dp[prev][1][2]);
    }
    int last = (N - 1) & 1;
    cout << max({ dp[last][0][0], dp[last][0][1], dp[last][0][2] }) << ' ' << min({ dp[last][1][0], dp[last][1][1], dp[last][1][2] });

    return 0;
}