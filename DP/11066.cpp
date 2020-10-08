#include <iostream>

using namespace std;

#define INF (int)(5e7)

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int dp[501][501] = { 0, };
        int ps[501] = { 0, };
        int K;
        cin >> K;
        int in;
        for (int i = 1; i <= K; ++i)
        {
            cin >> in;
            ps[i] = ps[i - 1] + in;
        }
        for (int i = 1; i < K; ++i)
        {
            for (int from = 1; from + i <= K; ++from)
            {
                int to = from + i;
                dp[from][to] = INF;
                for (int mid = from; mid < to; ++mid)
                    dp[from][to] = min(dp[from][to], dp[from][mid] + dp[mid + 1][to]);
                dp[from][to] +=  ps[to] - ps[from - 1];
            }
        }
        cout << dp[1][K] << '\n';
    }

    return 0;
}