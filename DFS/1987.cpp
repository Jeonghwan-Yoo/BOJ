#include <iostream>

using namespace std;

char board[22][22];
int alpha;
int R, C;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int maxCnt;

void Dfs(int r, int c, int cnt)
{
    for (int dir = 0; dir < 4; ++dir)
    {
        int nr = r + dy[dir];
        int nc = c + dx[dir];
        if (board[nr][nc] == 0)
            continue;
        if ((1 << (board[nr][nc] - 'A') & alpha) != 0)
            continue;
        alpha ^= 1 << (board[nr][nc] - 'A');
        Dfs(nr, nc, cnt + 1);
        alpha ^= 1 << (board[nr][nc] - 'A');
    }
    if (maxCnt < cnt)
        maxCnt = cnt;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            cin >> board[i][j];
    
    alpha |= 1 << (board[1][1] - 'A');
    Dfs(1, 1, 1);
    cout << maxCnt;

    return 0;
}