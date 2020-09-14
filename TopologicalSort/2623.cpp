#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool adj[1'001][1'001];
bool visited[1'001];
vector<int> order;

void Dfs(int src)
{
    visited[src] = true;
    for (int i = 1; i <= N; ++i)
        if (!visited[i] && adj[src][i])
            Dfs(i);
        
    order.emplace_back(src);
}

void TopologicalSort()
{
    for (int i = 1; i <= N; ++i)
        if (!visited[i])
            Dfs(i);
    
    reverse(order.begin(), order.end());

    for (int i = 0; i < (int)order.size(); ++i)
    {
        for (int j = i + 1; j < (int)order.size(); ++j)
        {
            if (adj[order[j]][order[i]])
            {
                order.clear();
                return;
            }
        }
    }
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
            adj[from][to] = true;
            from = to;
        }
    }
    TopologicalSort();
    
    if (order.empty())
        cout << 0;
    else
        for (int i = 0; i < (int)order.size(); ++i)
            cout << order[i] << '\n';

    return 0;
}