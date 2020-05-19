#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int dp[100'001] = { 0, };
    for (int i = 0; i < 100'001; ++i)
        dp[i] = 5;
    dp[0] = 0;
    for (int i = 1; i * i <= N; ++i)
        for (int j = i * i; j <= N; ++j)
            dp[j] = min(dp[j], dp[j - i * i] + 1);

    cout << dp[N];
    
    return 0;
}