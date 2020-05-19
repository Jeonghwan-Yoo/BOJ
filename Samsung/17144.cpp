#include <iostream>
#include <queue>

using namespace std;

const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

int R, C, T;
int board[51][51];

struct Purifier
{
    int ur, uc;
    int dr, dc;
    void Purify()
    {
        int wur = ur;
        int wuc = uc;
        --wur;
        while (wur > 0)
        {
            --wur;
            board[wur + 1][wuc] = board[wur][wuc];
        }
        while (wuc < C - 1)
        {
            ++wuc;
            board[wur][wuc - 1] = board[wur][wuc];
        }
        while (wur < ur)
        {
            ++wur;
            board[wur - 1][wuc] = board[wur][wuc];
        }
        while (wuc > 0)
        {
            --wuc;
            board[wur][wuc + 1] = board[wur][wuc];
        }
        board[wur][wuc + 1] = 0;

        int wdr = dr;
        int wdc = dc;
        ++wdr;
        while (wdr < R - 1)
        {
            ++wdr;
            board[wdr - 1][wdc] = board[wdr][wdc];
        }
        while (wdc < C - 1)
        {
            ++wdc;
            board[wdr][wdc - 1] = board[wdr][wdc];
        }
        while (wdr > dr)
        {
            --wdr;
            board[wdr + 1][wdc] = board[wdr][wdc];
        }
        while (wdc > 0)
        {
            --wdc;
            board[wdr][wdc + 1] = board[wdr][wdc];
        }
        board[wdr][wdc + 1] = 0;

    }

};
Purifier purifier;

struct Dust
{
    int r, c, val;
};

void Extend()
{
    queue<Dust> q;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] > 0)
                q.push({ i, j, board[i][j] });
    while(!q.empty())
    {
        int curR = q.front().r;
        int curC = q.front().c;
        int curV = q.front().val;
        int sumV = 0;
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int nxtR = curR + dr[dir];
            int nxtC = curC + dc[dir];
            int nxtV = curV / 5;
            if (nxtR < 0 || nxtR >= R || nxtC < 0 || nxtC >= C)
                continue;
            if (board[nxtR][nxtC] == -1)
                continue;
            board[nxtR][nxtC] += nxtV;
            sumV += nxtV;
        }
        board[curR][curC] -= sumV;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    purifier.ur = -1;
    purifier.uc = -1;
    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == -1)
            {
                if (purifier.ur == -1 && purifier.uc == -1)
                {
                    purifier.ur = i;
                    purifier.uc = j;
                }
                else
                {
                    purifier.dr = i;
                    purifier.dc = j;
                }
            }
        }
    }

    while (T--)
    {
        Extend();
        purifier.Purify();
    }
    int cnt = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] > 0)
                cnt += board[i][j];
        
    cout << cnt;
    
    return 0;
}