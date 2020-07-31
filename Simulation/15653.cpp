#include <iostream>
#include <queue>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

int N, M;
char board[11][11];
bool visited[11][11][11][11];

struct Beads
{
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
    Beads(int rx, int ry, int bx, int by, int cnt)
     : rx(rx), ry(ry), bx(bx), by(by), cnt(cnt) {}
};

int Lean(int rx, int ry, int bx, int by)
{
    queue<Beads> q;
    q.emplace(rx, ry, bx, by, 0);
    visited[ry][rx][by][bx] = true;
    while (!q.empty())
    {
        int crx = q.front().rx;
        int cry = q.front().ry;
        int cbx = q.front().bx;
        int cby = q.front().by;
        int ccnt = q.front().cnt;
        q.pop();
        board[cry][crx] = 'R';
        board[cby][cbx] = 'B';
        for (int dir = 0; dir < 4; ++dir)
        {
            int nrx = crx + dx[dir];
            int nry = cry + dy[dir];
            int nbx = cbx + dx[dir];
            int nby = cby + dy[dir];
            int rc = 0;
            int bc = 0;
            while (board[nry][nrx] == '.' || board[nry][nrx] == 'B')
            {
                ++rc;
                nrx += dx[dir];
                nry += dy[dir];
            }
            while (board[nby][nbx] == '.' || board[nby][nbx] == 'R')
            {
                ++bc;
                nbx += dx[dir];
                nby += dy[dir];
            }

            if (board[nby][nbx] == 'O')
                continue;

            if (board[nry][nrx] == 'O')
                return ccnt + 1;

            nrx -= dx[dir];
            nry -= dy[dir];
            nbx -= dx[dir];
            nby -= dy[dir];
            if (nrx == nbx && nry == nby)
            {
                if (rc > bc)
                {
                    nrx -= dx[dir];
                    nry -= dy[dir];
                }
                else
                {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }
            
            if (visited[nry][nrx][nby][nbx] == false)
            {
                visited[nry][nrx][nby][nbx] = true;
                q.emplace(nrx, nry, nbx, nby, ccnt + 1);
            }
        }
        board[cry][crx] = '.';
        board[cby][cbx] = '.';
    }
    return -1;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rx, ry, bx, by;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                rx = j;
                ry = i;
            }
            else if (board[i][j] == 'B')
            {
                bx = j;
                by = i;
            }
        }
    }
    cout << Lean(rx, ry, bx, by);

    return 0;
}