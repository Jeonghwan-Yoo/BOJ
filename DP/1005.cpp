#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> time;
vector<int> adj[1001];
vector<int> visited;
vector<int> order;

void Dfs(int src)
{
    visited[src] = 1;
    for (int i = 0; i < adj[src].size(); ++i)
    {
        int nxt = adj[src][i];
        if (visited[nxt] == 0)
        {
            Dfs(nxt);
        }
    }
    order.push_back(src);
}

void TopologicalSort()
{
    for (int i = 0; i < visited.size(); ++i)
    {
        if (visited[i] == 0)
        {
            Dfs(i);
        }
    }
    reverse(order.begin(), order.end());
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        time.assign(N, 0);
        visited.assign(N, 0);
        order.clear();
        for (int i = 0; i < 1001; ++i)
            adj[i].clear();
        for (int i = 0; i < N; ++i)
        {
            cin >> time[i];
        }
        for (int i = 0; i < K; ++i)
        {
            int from, to;
            cin >> from >> to;
            --from;
            --to;
            adj[from].push_back(to);
        }
        int W;
        cin >> W;
        --W;
        TopologicalSort(); 
        vector<int> dp(time.begin(), time.end());
        for (int i = 0; i < order.size(); ++i)
        {
            for (int j = 0; j < adj[order[i]].size(); ++j)
            {
                dp[adj[order[i]][j]] = max(dp[adj[order[i]][j]], dp[order[i]] + time[adj[order[i]][j]]);
            }
        }
        cout << dp[W] << '\n';
    }
    return 0;
}