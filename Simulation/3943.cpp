#include <iostream>

using namespace std;

int dp[100'001];

int Hailstone(int n)
{
    if (n <= 100'000 && dp[n] > 0)
        return dp[n];

    int maxVal = 0;
    if ((n & 1) == 0)
        maxVal = max(n, Hailstone(n >> 1));
    else
        maxVal = max(n, Hailstone(3 * n + 1));
    
    if (n <= 100'000)
        dp[n] = maxVal;
    return maxVal;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    dp[1] = 1;
    int n;
    while (T--)
    {
        cin >> n;
        cout << Hailstone(n) << '\n';
    }

    return 0;
}