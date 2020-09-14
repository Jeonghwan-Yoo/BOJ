#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[10'001];
int indegree[10'001];
int time[10'001];
int dp[10'001];

void Dfs(int src)
{
    --indegree[src];
    for (auto &a : adj[src])
    {
        dp[a] = max(dp[a], dp[src] + time[a]);
        --indegree[a];
        if (indegree[a] == 0)
            Dfs(a);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> time[i];
        dp[i] = time[i];
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            int a;
            cin >> a;
            adj[a].emplace_back(i);
            ++indegree[i];
        }
    }
    
    for (int i = 1; i <= N; ++i)
        if (indegree[i] == 0)
            Dfs(i);

    int maxVal = 0;
    for (int i = 1; i <= N; ++i)
        maxVal = max(maxVal, dp[i]);
    
    cout << maxVal;

    return 0;
}