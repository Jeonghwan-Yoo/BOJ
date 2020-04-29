#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum Def
{
    Unvisited = 0,
    Visited = 1,
    Max = 8,
};

const int dx[Def::Max] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[Def::Max] = { -1, -1, 0, 1, 1, 1, 0, -1 };

char board[Def::Max][Def::Max];


bool Check(int nr, int nc)
{
    if ((nr < 0) || (nr >= Def::Max) || (nc < 0) || (nc >= Def::Max))
        return false;
    if (isalpha(board[nr][nc]))
        return false;
    return true;
}

void Move(int r, int c, char ch)
{
    switch (ch)
    {
        case 'r':
        case 'R':
        {
            for (int dir = 0; dir < Def::Max; dir += 2)
            {
                int nr = r;
                int nc = c;
                while (1)
                {
                    nr += dy[dir];
                    nc += dx[dir];
                    if (Check(nr, nc) == false)
                        break;
                    board[nr][nc] = Def::Visited;
                }
            }
            break;
        }
        case 'n':
        case 'N':
        {
            for (int dir = 0; dir < Def::Max; ++dir)
            {
                int nr = r + dy[dir] + dy[(dir + 1) & 7];
                int nc = c + dx[dir] + dx[(dir + 1) & 7];
                if (Check(nr, nc) == false)
                    continue;
                board[nr][nc] = Def::Visited;
            }
            break;
        }
        case 'b':
        case 'B':
        {
            for (int dir = 1; dir < Def::Max; dir += 2)
            {
                int nr = r;
                int nc = c;
                while (1)
                {
                    nr += dy[dir];
                    nc += dx[dir];
                    if (Check(nr, nc) == false)
                        break;
                    board[nr][nc] = Def::Visited;
                }
            }
            break;
        }
        case 'q':
        case 'Q':
        {
            for (int dir = 0; dir < Def::Max; ++dir)
            {
                int nr = r;
                int nc = c;
                while (1)
                {
                    nr += dy[dir];
                    nc += dx[dir];
                    if (Check(nr, nc) == false)
                        break;
                    board[nr][nc] = Def::Visited;
                }
            }
            break;
        }
        case 'k':
        case 'K':
        {
            for (int dir = 0; dir < Def::Max; ++dir)
            {
                int nr = r + dy[dir];
                int nc = c + dx[dir];
                if (Check(nr, nc) == false)
                    continue;
                board[nr][nc] = Def::Visited;
            }
            break;
        }
        case 'p':
        {
            for (int dir = 3; dir < 5; ++dir)
            {
                int nr = r + dy[dir] + dy[dir + 1] + dy[0];
                int nc = c + dx[dir] + dx[dir + 1] + dx[0];
                if (Check(nr, nc) == false)
                    continue;
                board[nr][nc] = Def::Visited;
            }
            break;
        }
        case 'P':
        {
            for (int dir = -1; dir < 1; ++dir)
            {
                int nr = r + dy[(dir + 8) & 7] + dy[dir + 1] + dy[4];
                int nc = c + dx[(dir + 8) & 7] + dx[dir + 1] + dx[4];
                if (Check(nr, nc) == false)
                    continue;
                board[nr][nc] = Def::Visited;
            }
            break;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string in;
    while (cin >> in)
    {
        memset(board, Def::Unvisited, sizeof(board));
        int r = 0;
        int c = 0;
        for (int i = 0; i < in.size(); ++i)
        {
            if (isdigit(in[i]) == true)
            {
                c += in[i] - '0';
            }
            else if (in[i] == '/')
            {
                r += 1;
                c = 0;
            }
            else
            {
                board[r][c] = in[i];
                ++c;
            }
        }
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                Move(i, j, board[i][j]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (board[i][j] == Def::Unvisited)
                    ++cnt;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}