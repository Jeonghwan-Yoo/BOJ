#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int adj[101];
bool visited[101];
bool finished[101];
vector<int> cycle;

void Dfs(int src)
{
    visited[src] = true;
    int nextSrc = adj[src];
    if (visited[nextSrc] == false)
        Dfs(nextSrc);
    else if (finished[nextSrc] == false)
    {
        cycle.emplace_back(src);
        for (int i = nextSrc; i != src; i = adj[i])
            cycle.emplace_back(i);
    }
    finished[src] = true;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> adj[i];
    
    for (int i = 1; i <= N; ++i)
        Dfs(i);
    
    sort(cycle.begin(), cycle.end());
    cout << (int)cycle.size() << '\n';
    for (int i = 0; i < (int)cycle.size(); ++i)
        cout << cycle[i] << '\n';

    return 0;
}