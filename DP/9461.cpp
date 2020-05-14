#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int dp[101] = { 0, };
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= 101; ++i)
        dp[i] = dp[i - 2] + dp[i - 3];
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