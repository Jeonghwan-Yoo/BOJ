#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int constexpr dy[4] = { -1, 0, 1, 0 };
int constexpr dx[4] = { 0, 1, 0, -1 };

int n, m;

int Dfs(int y, int x, vector<vector<int>> &board, vector<vector<int>> &visited)
{
    int ret = 1;
    for (int dir = 0; dir < 4; ++dir)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (visited[ny][nx])
            continue;
        visited[ny][nx] = 1;

        if (board[ny][nx])
            ret += Dfs(ny, nx, board, visited);
    }

    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    vector<vector<int>> visited(n, vector<int>(m));
    int work = 0;
    int maxSz = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (visited[i][j])
                continue;
            visited[i][j] = 1;

            if (board[i][j])
            {
                ++work;
                maxSz = max(maxSz, Dfs(i, j, board, visited));
            }
        }
    }
    cout << work << '\n' << maxSz;

    return 0;
}