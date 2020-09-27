#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; ++i)
        cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end());

    vector<int> dp(n);
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (ab[i].second > ab[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
    }
    int maxVal = 0;
    for (int i = 0; i < n; ++i)
        maxVal = max(maxVal, dp[i]);
    cout << n - maxVal;

    return 0;
}