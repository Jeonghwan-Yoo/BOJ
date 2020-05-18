#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int sticker[2][100'001] = { 0, };
        int N;
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> sticker[0][i];
        for (int i = 1; i <= N; ++i)
            cin >> sticker[1][i];
        int dp[2][100'001] = { 0, };
        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];
        for (int i = 2; i <= N; ++i)
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
        }
        cout << max(dp[0][N], dp[1][N]) << '\n';;
    }
    
    return 0;
}