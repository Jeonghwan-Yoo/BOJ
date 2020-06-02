#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dp[2][101][101];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int n1 = (int)s1.size();
    int n2 = (int)s2.size();
    int n3 = (int)s3.size();
    for (int i = 1; i <= n1; ++i)
    {
        for (int j = 1; j <= n2; ++j)
        {
            for (int k = 1; k <= n3; ++k)
            {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                    dp[i & 1][j][k] = dp[(i - 1) & 1][j - 1][k - 1] + 1;
                else
                    dp[i & 1][j][k] = max({ dp[(i - 1) & 1][j][k], dp[i & 1][j - 1][k], dp[i & 1][j][k - 1] });
            }
        }
    }
    cout << dp[n1 & 1][n2][n3];

    return 0;
}