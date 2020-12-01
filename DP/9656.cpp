#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> dp(max(4, N + 1));
    dp[1] = 1;
    dp[3] = 1;
    for (int i = 4; i <= N; ++i)
    {
        if (dp[i - 1] == 1 && dp[i - 3] == 1)
            dp[i] = 0;
        else
            dp[i] = 1;
    }
    cout << ((dp[N] == 0) ? "SK" : "CY");

    return 0;
}