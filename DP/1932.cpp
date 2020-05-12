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
    int arr[501][501] = { 0, };
    int dp[501][501] = { 0, };
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            cin >> arr[i][j];
    dp[1][1] = arr[1][1];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
    int maxVal = 0;
    for (int i = 1; i <= N; ++i)
        maxVal = max(maxVal, dp[N][i]);
    cout << maxVal;
    return 0;
}