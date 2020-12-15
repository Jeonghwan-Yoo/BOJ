#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int constexpr dy[4] = { -1, 0, 1, 0 };
int constexpr dx[4] = { 0, 1, 0, -1 };

int N, M, K;

int Dfs(int y, int x, vector<vector<int>> &board, vector<vector<int>> &visited)
{
    int ret = 1;

    for (int dir = 0; dir < 4; ++dir)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny <= 0 || ny > N || nx <= 0 || nx > M)
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
    
    cin >> N >> M >> K;
    vector<vector<int>> board(N + 1, vector<int>(M + 1));
    for (int i = 0; i < K; ++i)
    {
        int r, c;
        cin >> r >> c;
        board[r][c] = 1;
    }
    
    vector<vector<int>> visited(N + 1, vector<int>(M + 1));
    int maxSize = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (visited[i][j])
                continue;
            visited[i][j] = 1;

            if (board[i][j])
                maxSize = max(maxSize, Dfs(i, j, board, visited));
        }
    }
    cout << maxSize;

    return 0;
}