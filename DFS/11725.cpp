#include <iostream>
#include <vector>

using namespace std;

#define ROOT 1

int N;
vector<int> adj[100'001];
int parent[100'001];

void FindParent(int src)
{
    for (int i = 0; i < (int)adj[src].size(); ++i)
    {
        if (parent[adj[src][i]] != 0)
            continue;
        parent[adj[src][i]] = src;
        FindParent(adj[src][i]);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent[1] = 1;
    FindParent(ROOT);
    for (int i = 2; i <= N; ++i)
        cout << parent[i] << '\n';

    return 0;
}