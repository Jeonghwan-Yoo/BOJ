#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[10'001];
bool visited[10'001];
int maxNum;
int num;

void Dfs(int src)
{
    visited[src] = true;
    for (auto &a : adj[src])
    {
        if (visited[a] == false)
        {
            ++num;
            Dfs(a);
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        adj[b].emplace_back(a);
    }

    vector<int> computer;
    for (int i = 1; i <= N; ++i)
    {
        memset(visited, false, sizeof(visited));
        num = 0;
        Dfs(i);
        if (num > maxNum)
        {
            maxNum = num;
            computer.clear();
        }
        if (num == maxNum)
            computer.emplace_back(i);
    }
    for (int i = 0; i < (int)computer.size(); ++i)
        cout << computer[i] << ' ';

    return 0;
}