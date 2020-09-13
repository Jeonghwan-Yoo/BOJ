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
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        if (indegree[i] == 0)
        {
            --indegree[i];
            q.emplace(i);
            break;
        }
    }
        
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        order.emplace_back(cur);
        for (auto &a : adj[cur])
            --indegree[a];
        for (int i = 1; i <= N; ++i)
        {
            if (indegree[i] == 0)
            {
                --indegree[i];
                q.emplace(i);
                break;
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