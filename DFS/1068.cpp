#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[51];
int erase;

int Dfs(int src)
{
    if (src == erase)
        return 0;
    if ((int)adj[src].size() == 0 || ((int)adj[src].size() == 1 && adj[src][0] == erase))
        return 1;
    int ret = 0;
    for (auto &a : adj[src])
        ret += Dfs(a);
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int parent;
    int root;
    for (int i = 0; i < N; ++i)
    {
        cin >> parent;
        if (parent == -1)
            root = i;
        else
            adj[parent].emplace_back(i);
    }
    cin >> erase;
    
    cout << Dfs(root);

    return 0;
}