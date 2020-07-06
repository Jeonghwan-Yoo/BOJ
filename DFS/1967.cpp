#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Graph
{
    int to, weight;
};

vector<Graph> adj[10'001];
int visited[10'001];
int start = 1;

void Dfs(int src)
{
    for (auto &a : adj[src])
    {
        if (visited[a.to] == 0 && a.to != start)
        {
            visited[a.to] = visited[src] + a.weight;
            Dfs(a.to);
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
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }
    Dfs(start);
    int maxLen = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (maxLen < visited[i])
        {
            maxLen = visited[i];
            start = i;
        }
    }
    maxLen = 0;
    memset(visited, 0, sizeof(visited));
    Dfs(start);
    for (int i = 1; i <= N; ++i)
        if (maxLen < visited[i])
            maxLen = visited[i];
    cout << maxLen;
    
    return 0;
}