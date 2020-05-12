#include <iostream>
#include <algorithm>

using namespace std;

int dp[11];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 10; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }
    return 0;
}