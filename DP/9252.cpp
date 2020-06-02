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

    int n = (int)s1.size();
    int m = (int)s2.size();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string res;
    int x = m;
    int y = n;
    while (x > 0 && y > 0)
    {
        if (dp[y][x] == dp[y - 1][x])
            --y;
        else if (dp[y][x] == dp[y][x - 1])
            --x;
        else
        {
            --x;
            --y;
            res += s1[y];
        }
    }
    cout << dp[n][m] << '\n';
    for (int i = (int)res.size() - 1; i >= 0; --i)
        cout << res[i];
    
    return 0;
}