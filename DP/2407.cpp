#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string Add(string const &a, string const &b)
{
    string ret;
    int aSize = (int)a.size();
    int bSize = (int)b.size();
    int aPos = aSize - 1;
    int bPos = bSize - 1;
    int carry = 0;
    while (aPos >= 0 && bPos >= 0)
    {
        int num = a[aPos] - '0' + b[bPos] - '0' + carry;
        if (num >= 10)
        {
            carry = 1;
            num -= 10;
        }
        else
            carry = 0;
        ret += to_string(num);
        --aPos;
        --bPos;
    }
    while (aPos >= 0)
    {
        int num = a[aPos] - '0' + carry;
        if (num >= 10)
        {
            carry = 1;
            num -= 10;
        }
        else
            carry = 0;
        ret += to_string(num);
        --aPos;
    }
    while (bPos >= 0)
    {
        int num = b[bPos] - '0' + carry;
        if (num >= 10)
        {
            carry = 1;
            num -= 10;
        }
        else
            carry = 0;
        ret += to_string(num);
        --bPos;
    }
    if (carry)
        ret += "1";

    reverse(ret.begin(), ret.end());

    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<string>> dp(n + 1, vector<string>(n + 1));
    dp[1][0] = dp[1][1] = "1";
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = "1";
        for (int j = 1; j <= i; ++j)
            dp[i][j] = Add(dp[i - 1][j - 1], dp[i - 1][j]);
    }
    cout << dp[n][m];

    return 0;
}