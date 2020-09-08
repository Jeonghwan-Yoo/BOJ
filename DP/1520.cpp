#include <iostream>
#include <cstring>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

int N, M;
int board[501][501];
int dp[501][501];

int Dfs(int x, int y)
{
    if (x == M - 1 && y == N - 1)
        return 1;

    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
        
    ret = 0;
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        if (board[ny][nx] < board[y][x])
            ret += Dfs(nx, ny);
    }

    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
    
    memset(dp, -1, sizeof(dp));

    cout << Dfs(0, 0);

    return 0;
}