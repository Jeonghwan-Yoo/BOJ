#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MOD (int)1e6

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] != '0')
            dp[i + 1] = dp[i];
        
        int toNum = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if (i >= 1 && 10 <= toNum && toNum <= 26)
            dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
    }
    cout << dp[n];

    return 0;
}