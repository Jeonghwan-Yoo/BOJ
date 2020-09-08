#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[1'001];
    int dp[1'001] = { 0, };
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    for (int i = 0; i < N; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (a[i] < a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }
    int maxVal = 0;
    for (int i = 0; i < N; ++i)
        if (maxVal < dp[i])
            maxVal = dp[i];
    cout << maxVal;

    return 0;
}