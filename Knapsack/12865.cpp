#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> dp(K + 1);
    int w, v;
    for (int i = 0; i < N; ++i)
    {
        cin >> w >> v;
        for (int j = K; j >= w; --j)
            dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[K];

    return 0;
}