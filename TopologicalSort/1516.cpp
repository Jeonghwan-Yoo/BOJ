#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> time;
vector<int> adj[501];
vector<int> order;

void TopologicalSort(int n)
{
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < adj[i].size(); ++j)
        {
            ++indegree[adj[i][j]];
        }
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for (int i = 0; i < adj[cur].size(); ++i)
        {
            --indegree[adj[cur][i]];
            if (indegree[adj[cur][i]] == 0)
            {
                q.push(adj[cur][i]);
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int t;
        cin >> t;
        time.push_back(t);
        int prev;
        while (cin >> prev)
        {
            if (prev == -1)
            {
                break;
            }
            --prev;
            adj[prev].push_back(i);
        }
    }
    TopologicalSort(N);
    vector<int> dp(time.begin(), time.end());
    for (auto &o : order)
    {
        for (auto &a : adj[o])
        {
            dp[a] = max(dp[a], dp[o] + time[a]); 
        }
    }
    for (int i = 0; i < N; ++i)
        cout << dp[i] << '\n';
    
    return 0;
}