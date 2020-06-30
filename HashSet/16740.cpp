#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[5'001][5'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v;
    v.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    int maxDiff = 0;
    int diff;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            diff = v[i] - v[j];
            int idx = lower_bound(v.begin(), v.end(), v[j] - diff) - v.begin();
            if (v[j] - v[idx] == v[i] - v[j])
                dp[i][j] = max(dp[i][j], dp[j][idx] + 1);
            maxDiff = max(maxDiff, dp[i][j]);
        }
    }
    cout << maxDiff + 2;

    return 0;
}