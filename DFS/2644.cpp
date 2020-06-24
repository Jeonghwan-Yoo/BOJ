#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[101];
bool visited[101];
int diff;

void Dfs(int src, int dst, int cnt)
{
    for (auto &a : adj[src])
    {
        if (visited[a] == true)
            continue;
        visited[a] = true;
        if (a == dst)
        {
            diff = cnt + 1;
            return;
        }
        Dfs(a, dst, cnt + 1);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, a, b, M;
    cin >> N >> a >> b >> M;
    for (int i = 0; i < M; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }
    Dfs(a, b, 0);
    if (diff == 0)
        cout << -1;
    else
        cout << diff;

    return 0;
}