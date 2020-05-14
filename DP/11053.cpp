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
    int arr[1'001] = { 0, };
    int dp[1'001] = { 0, };
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];
    for (int i = 1; i <= N; ++i)
    {
        dp[i] = 1;
        for (int j = 1; j < i; ++j)
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    cout << *max_element(dp + 1, dp + N + 1);
    return 0;
}