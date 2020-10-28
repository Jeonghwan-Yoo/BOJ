#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    vector<vector<long long>> dp(N, vector<long long>(21));
    dp[0][arr[0]] = 1;
    for (int i = 1; i < N - 1; ++i)
    {
        for (int j = 0; j <= 20; ++j)
        {
            if (j - arr[i] >= 0)
                dp[i][j] += dp[i - 1][j - arr[i]];
            if (j + arr[i] <= 20)
                dp[i][j] += dp[i - 1][j + arr[i]];
        }
    }
    cout << dp[N - 2][arr[N - 1]];

    return 0;
}