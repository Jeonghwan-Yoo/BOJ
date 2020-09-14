#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxVal = 0;
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int t, n;
        cin >> t >> n;
        for (int j = 0; j < n; ++j)
        {
            int a;
            cin >> a;
            dp[i] = max(dp[i], dp[a]);
        }
        dp[i] += t;
        maxVal = max(maxVal, dp[i]);
    }
    
    cout << maxVal;

    return 0;
}