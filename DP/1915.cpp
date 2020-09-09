#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dp[1'001][1'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string s;
    int maxVal = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        for (int j = 1; j <= m; ++j)
        {
            if (s[j - 1] == '1')
            {
                dp[i][j] = min({ dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1] }) + 1;
                if (maxVal < dp[i][j])
                    maxVal = dp[i][j];
            }
        }
    }
    cout << maxVal * maxVal;

    return 0;
}