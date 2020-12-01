#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> m(N);
    vector<int> c(N);
    for (int i = 0; i < N; ++i)
        cin >> m[i];
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> c[i];
        sum += c[i];
    }
    
    vector<int> dp(sum + 1);
    for (int i = 0; i < N; ++i)
        for (int j = sum; j >= c[i]; --j)
            dp[j] = max(dp[j], dp[j - c[i]] + m[i]);

    for (int i = 0; i <= sum; ++i)
    {
        if (dp[i] >= M)
        {
            cout << i;
            break;    
        }
    }

    return 0;
}