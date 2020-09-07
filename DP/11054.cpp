#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S[1'001];
    int dp[2][1'001] = { 0, };
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> S[i];

    for (int i = 0; i < N; ++i)
    {
        dp[0][i] = 1;
        for (int j = 0; j < i; ++j)
            if (S[i] > S[j])
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);
    }
    for (int i = N - 1; i >= 0; --i)
    {
        dp[1][i] = 1;
        for (int j = N - 1; j > i; --j)
            if (S[i] > S[j])
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);
    }
    int maxVal = 0;
    for (int i = 0; i < N; ++i)
        if (maxVal < dp[0][i] + dp[1][i])
            maxVal = dp[0][i] + dp[1][i];
    cout << maxVal - 1;

    return 0;
}