#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define INF INT_MAX

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> row(N);
    vector<int> col(N);
    vector<vector<int>> dp(501, vector<int>(501));
    for (int i = 0; i < N; ++i)
        cin >> row[i] >> col[i];

    for (int to = 1; to < N; ++to)
    {
        for (int from = to - 1; from >= 0; --from)
        {
            dp[from][to] = INF;
            for (int mid = from; mid < to; ++mid)
                dp[from][to] = min(dp[from][to], dp[from][mid] + dp[mid + 1][to] + row[from] * col[mid] * col[to]);
        }
    }
    cout << dp[0][N - 1];

    return 0;
}