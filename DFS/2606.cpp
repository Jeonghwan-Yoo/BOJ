#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[101];
bool visited[101];

void Dfs(int src)
{
    visited[src] = true;
    for (int i = 0; i < adj[src].size(); ++i)
    {
        if (visited[adj[src][i]] == true)
            continue;
        Dfs(adj[src][i]);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Dfs(1);
    int cnt = 0;
    for (int i = 2; i <= N; ++i)
        cnt += visited[i];
    cout << cnt;
    return 0;
}