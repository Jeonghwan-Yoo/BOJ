#include <iostream>
#include <vector>

using namespace std;

bool Dfs(int src, int num, vector<int> &visited, vector<vector<int>> const &adj)
{
    if (num == 5)
        return true;
        
    visited[src] = 1;

    bool ret = false;
    for (auto &a : adj[src])
        if (!visited[a])
            ret |= Dfs(a, num + 1, visited, adj);

    visited[src] = 0;
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    vector<int> visited(N);
    bool flag = false;
    for (int i = 0; i < N; ++i)
    {
        flag = Dfs(i, 1, visited, adj);
        if (flag == true)
            break;
    }
    cout << flag;

    return 0;
}