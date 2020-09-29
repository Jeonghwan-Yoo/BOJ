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
    vector<int> dp(max(5, N + 1));
    dp[1] = 1;
    dp[3] = 1;
    dp[2] = 2;
    dp[4] = 2;
    for (int i = 5; i <= N; ++i)
    {
        if (dp[i - 1] == 2 || dp[i - 3] == 2)
            dp[i] = 1;
        else
            dp[i] = 2;
    }
    cout << ((dp[N] == 1) ? "SK" : "CY");

    return 0;
}