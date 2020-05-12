#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9

int dp[5000];

int Delivery(int N)
{
    if (N < 3)
        return INF;
    int &ret = dp[N];
    if (ret != INF)
        return ret;
    return ret = min(Delivery(N - 3), Delivery(N - 5)) + 1;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    fill(dp, dp + N + 1, INF);
    dp[3] = 1;
    dp[5] = 1;
    int ret = Delivery(N);
    if (ret >= INF)
        ret = -1;
    cout << ret;
    return 0;
}