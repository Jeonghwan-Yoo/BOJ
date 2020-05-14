#include <iostream>

using namespace std;

char board[21][21];
bool alpha[26];
int R, C;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int maxCnt;

void Dfs(int r, int c, int cnt)
{
    bool check = false;
    for (int dir = 0; dir < 4; ++dir)
    {
        int nr = r + dy[dir];
        int nc = c + dx[dir];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C)
            continue;
        if (alpha[board[nr][nc] - 'A'] == true)
            continue;
        check = true;
        alpha[board[nr][nc] - 'A'] = true;
        Dfs(nr, nc, cnt + 1);
        alpha[board[nr][nc] - 'A'] = false;
    }
    if (check == false)
        if (maxCnt < cnt)
            maxCnt = cnt;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];
    
    alpha[board[0][0] - 'A'] = true;
    Dfs(0, 0, 1);
    cout << maxCnt;

    return 0;
}