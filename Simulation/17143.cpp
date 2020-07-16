#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int dx[4] = { 0, 0, 1, -1 };
constexpr int dy[4] = { -1, 1, 0, 0 };

int R, C, M;

struct Shark
{
    int s, d, z;
    void Delete()
    {
        s = 0;
        d = 0;
        z = 0;
    }
};

Shark board[2][101][101];

struct Fisherman
{
    int x, y;
    int amount;
    void Move()
    {
        x += 1;
    }
    void Catch(int cur)
    {
        for (int i = 0; i < R; ++i)
        {
            if (board[cur][i][x].z != 0)
            {
                amount += board[cur][i][x].z;
                board[cur][i][x].Delete();
                return;
            }
        }
    }
};

Fisherman fisherman;

void SharkMove(int cur)
{
    int next = (cur + 1) & 1;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            board[next][i][j].Delete();

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (board[cur][i][j].z > 0)
            {
                int y = i;
                int x = j;
                int s = board[cur][i][j].s;
                int &d = board[cur][i][j].d;
                int z = board[cur][i][j].z;
                if (d < 2)
                {
                    int ny = (y + s * dy[d] + ((R - 1) << 10)) % ((R - 1) << 1);
                    if (ny > R - 1)
                    {
                        d ^= 1;
                        ny = ((R - 1) << 1) - ny;
                    }
                    if (board[next][ny][x].z < z)
                        board[next][ny][x] = board[cur][y][x];
                }
                else
                {
                    int nx = (x + s * dx[d] + ((C - 1) << 10)) % ((C - 1) << 1);
                    if (nx > C - 1)
                    {
                        d ^= 1;
                        nx = ((C - 1) << 1) - nx;
                    }
                    if (board[next][y][nx].z < z)
                        board[next][y][nx] = board[cur][y][x];
                }
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C >> M;
    for (int i = 0; i < M; ++i)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        --r;
        --c;
        --d;
        board[0][r][c] = { s, d, z };
    }
    fisherman.x = -1;
    int cur = 0;
    int t = C;
    while (t--)
    {
        fisherman.Move();
        fisherman.Catch(cur);
        SharkMove(cur);
        cur = (cur + 1) & 1;
    }
    cout << fisherman.amount;

    return 0;
}