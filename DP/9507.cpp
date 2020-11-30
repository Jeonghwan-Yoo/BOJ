#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dp[68] = { 1, 1, 2, 4 };
    for (int i = 4; i <= 67; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}