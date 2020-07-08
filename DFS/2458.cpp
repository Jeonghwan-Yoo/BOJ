#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> taller[501];
bool visited[501];
int totalVisited[501];

int Dfs(int src)
{
    int ret = 0;
    for (auto &t : taller[src])
    {
        if (visited[t] == false)
        {
            visited[t] = true;
            ++totalVisited[t];
            ret += Dfs(t) + 1;
        }
    }
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        taller[a].emplace_back(b);
    }
    for (int i = 1; i <= N; ++i)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        totalVisited[i] += Dfs(i);
    }
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        if (totalVisited[i] == N - 1)
            ++cnt;
    cout << cnt;

    return 0;
}