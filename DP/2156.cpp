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
    int arr[10'001] = { 0, };
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];
    int dp[10'001] = { 0, };
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for (int i = 3; i <= N; ++i)
    {
        dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[N];
    return 0;
}