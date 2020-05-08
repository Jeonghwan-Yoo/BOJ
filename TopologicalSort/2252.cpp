#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> edge[32'001];
vector<int> visited;
vector<int> order;

void dfs(int src)
{
    visited[src] = 1;
    for (int i = 0; i < edge[src].size(); ++i)
        if (visited[edge[src][i]] == 0)
            dfs(edge[src][i]);
    order.push_back(src);
}

void TopologicalSort(int n)
{
    visited.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        if (visited[i] == 0)
                dfs(i);
    reverse(order.begin(), order.end());
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        edge[a].emplace_back(b);
    }
    TopologicalSort(N);
    for (int i = 0; i < order.size(); ++i)
        cout << order[i] << ' ';
    return 0;
}