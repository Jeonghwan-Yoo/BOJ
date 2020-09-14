#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> adj[1'001];
int indegree[1'001];
vector<int> order;

void Dfs(int src)
{
    --indegree[src];
    order.emplace_back(src);
    for (auto &a : adj[src])
    {
        --indegree[a];
        if (indegree[a] == 0)
            Dfs(a);
    }
}

void TopologicalSort()
{
    for (int i = 1; i <= N; ++i)
        if (!indegree[i])
            Dfs(i);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        int from, to;
        cin >> from;
        for (int j = 0; j < num - 1; ++j)
        {
            cin >> to;
            adj[from].emplace_back(to);
            from = to;
            ++indegree[to];
        }
    }
    TopologicalSort();
    
    if (order.size() < N)
        cout << 0;
    else
        for (int i = 0; i < (int)order.size(); ++i)
            cout << order[i] << '\n';

    return 0;
}