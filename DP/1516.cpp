#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Dfs(int idx, vector<int> const &arr, vector<vector<int>> const &adj, vector<int> &dp)
{
    int &ret = dp[idx];
    if (ret != -1)
        return ret;
    
    int tmp = 0;
    for (auto &a : adj[idx])
        tmp = max(tmp, Dfs(a, arr, adj, dp));
    ret = tmp + arr[idx];

    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> arr(N + 1);
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        int prev;
        while (1)
        {
            cin >> prev;
            if (prev == -1)
                break;

            adj[i].emplace_back(prev);
        }
    }
    vector<int> dp(N + 1, -1);
    for (int i = 1; i <= N; ++i)
        cout << Dfs(i, arr, adj, dp) << '\n';

    return 0;
}