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
    vector<int> dp(N);
    int maxLen = 0;
    for (int i = 0; i < N; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        maxLen = max(maxLen, dp[i]);
    }
    cout << N - maxLen;

    return 0;
}