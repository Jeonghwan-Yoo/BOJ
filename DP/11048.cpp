#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int dp[1'001] = { 0, };
    int in;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> in;
            dp[j] = max(dp[j], dp[j - 1]) + in;
        }
    }
    cout << dp[M];

    return 0;
}