#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1'000

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
    vector<int> dp(N, INF);
    dp[0] = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 1; j <= arr[i]; ++j) 
        {
            int nxt = i + j;
            if (nxt < N)
                dp[nxt] = min(dp[nxt], dp[i] + 1);
        }
    }
    if (dp[N - 1] == INF)
        cout << -1;
    else
        cout << dp[N - 1];

    return 0;
}