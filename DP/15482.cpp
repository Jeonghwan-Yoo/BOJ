#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1'001][1'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    int n = (int)s1.size() / 3;
    int m = (int)s2.size() / 3;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s1[(i - 1) * 3] == s2[(j - 1) * 3] && s1[(i - 1) * 3 + 1] == s2[(j - 1) * 3 + 1] && s1[(i - 1) * 3 + 2] == s2[(j - 1) * 3 + 2])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m];

    return 0;
}