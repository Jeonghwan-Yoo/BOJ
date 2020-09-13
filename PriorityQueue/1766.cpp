#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[32'001];
int indegree[32'001];
vector<int> order;

void TopologicalSort()
{
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 1; i <= N; ++i)
        if (indegree[i] == 0)
            pq.emplace(i);
        
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        order.emplace_back(cur);
        for (auto &a : adj[cur])
        {
            --indegree[a];
            if (indegree[a] == 0)
                pq.emplace(a);
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        adj[from].emplace_back(to);
        ++indegree[to];
    }

    TopologicalSort();

    for (int i = 0; i < N; ++i)
        cout << order[i] << ' ';

    return 0;
}