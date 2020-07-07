#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int> > adj[100'001];
bool visited[100'001];
int maxLen, maxIdx;

void Dfs(int src, int len)
{
    for (auto &a : adj[src])
    {
        if (visited[a.first] == false)
        {
            visited[a.first] = true;
            Dfs(a.first, len + a.second);
        }
    }
    if (maxLen < len)
    {
        maxLen = len;  
        maxIdx = src;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V;
    int a, b, w;
    for (int i = 0; i < V; ++i)
    {
        cin >> a;
        while (cin >> b)
        {
            if (b == -1)
                break;
            cin >> w;
            adj[a].emplace_back(b, w);
        }
    }
    visited[1] = true;
    Dfs(1, 0);
    memset(visited, false, sizeof(visited));
    visited[maxIdx] = true;
    Dfs(maxIdx, 0);
    cout << maxLen;

    return 0;
}