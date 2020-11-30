#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, M;
    cin >> N >> S >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    
    vector<vector<int>> dp(N, vector<int>(M + 1));
    if (S + arr[0] <= M)
        dp[0][S + arr[0]] = 1;
    if (S - arr[0] >= 0)
        dp[0][S - arr[0]] = 1;
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j <= M; ++j)
        {
            if (dp[i - 1][j])
            {
                if (j + arr[i] <= M)
                    dp[i][j + arr[i]] = 1;
                if (j - arr[i] >= 0)
                    dp[i][j - arr[i]] = 1;
            }
        }
    }

    int maxVol = -1;
    for (int i = 0; i <= M; ++i)
        if (dp[N - 1][i])
            maxVol = max(maxVol, i);
    cout << maxVol;

    return 0;
}