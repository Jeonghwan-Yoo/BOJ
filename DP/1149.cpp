#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int RGB[3][1'001] = { 0, };
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> RGB[j][i];
    int dp[3][1'001] = { 0, };
    for (int i = 1; i <= N; ++i)
    {
        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + RGB[0][i];
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + RGB[1][i];
        dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + RGB[2][i];
    }
    cout << min({ dp[0][N], dp[1][N], dp[2][N] });
    return 0;
}