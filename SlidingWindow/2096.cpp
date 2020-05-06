#include <iostream>
#include <algorithm>

using namespace std;

int dp[2][3][2];
int row[100001][3];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> row[i][j];

    dp[0][0][0] = dp[0][0][1] = row[0][0];
    dp[0][1][0] = dp[0][1][1] = row[0][1];
    dp[0][2][0] = dp[0][2][1] = row[0][2];
    for (int i = 1; i < N; ++i)
    {
        dp[i & 1][0][0] = max(dp[(i - 1) & 1][0][0], dp[(i - 1) & 1][1][0]) + row[i][0];
        dp[i & 1][0][1] = min(dp[(i - 1) & 1][0][1], dp[(i - 1) & 1][1][1]) + row[i][0];
        
        dp[i & 1][1][0] = max({ dp[(i - 1) & 1][0][0], dp[(i - 1) & 1][1][0], dp[(i - 1) & 1][2][0]}) + row[i][1];
        dp[i & 1][1][1] = min({ dp[(i - 1) & 1][0][1], dp[(i - 1) & 1][1][1], dp[(i - 1) & 1][2][1]}) + row[i][1];

        dp[i & 1][2][0] = max(dp[(i - 1) & 1][1][0], dp[(i - 1) & 1][2][0]) + row[i][2];
        dp[i & 1][2][1] = min(dp[(i - 1) & 1][1][1], dp[(i - 1) & 1][2][1]) + row[i][2];
    }
    cout << max({ dp[(N - 1) & 1][0][0], dp[(N - 1) & 1][1][0], dp[(N - 1) & 1][2][0] }) << ' ' << min({ dp[(N - 1) & 1][0][1], dp[(N - 1) & 1][1][1], dp[(N - 1) & 1][2][1] });

    return 0;
}