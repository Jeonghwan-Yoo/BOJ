#include <iostream>
#include <vector>

using namespace std;

int constexpr dx[2] = { 0, 1 };
int constexpr dy[2] = { -1, 0 };

void PushBlock(int t, int y, int x, int board[10][4], int idx)
{
    if (t == 1)
    {
        int pos = y;
        board[pos][x] = 0;
        while (pos < 10 && board[pos][x] == 0)
            ++pos;
        --pos;
        board[pos][x] = idx;
    }
    else if (t == 2)
    {
        int pos = y;
        board[pos][x] = board[pos][x + 1] = 0;
        while (pos < 10 && board[pos][x] == 0 && board[pos][x + 1] == 0)
            ++pos;
        --pos;
        board[pos][x] = board[pos][x + 1] = idx;
    }
    else
    {
        int pos = y + 1;
        board[pos][x] = board[pos - 1][x] = 0;
        while (pos < 10 && board[pos][x] == 0)
            ++pos;
        --pos;
        board[pos][x] = board[pos - 1][x] = idx;
    }
}

int Push(int t, int y, int x, int board[10][4], int idx)
{
    int line = 0;
    PushBlock(t, y, x, board, idx);
    bool check = true;
    while (check)
    {
        check = false;
        for (int i = 6; i < 10; ++i)
        {
            int cnt = 0;
            for (int j = 0; j < 4; ++j)
                if (board[i][j])
                    ++cnt;

            if (cnt == 4)
            {
                ++line;
                check = true;
                for (int j = 0; j < 4; ++j)
                    board[i][j] = 0;

                for (int pos = i; pos >= 4; --pos)
                {
                    for (int j = 0; j < 4; ++j)
                    {
                        if (board[pos][j] == 0)
                            continue;

                        int type = 1;
                        for (int d = 0; d < 2; ++d)
                        {
                            int ny = pos + dy[d];
                            int nx = j + dx[d];
                            if (ny < 4 || nx >= 4)
                                continue;

                            if (board[pos][j] == board[ny][nx])
                            {
                                if (d == 0)
                                    type = 3;
                                else if (d == 1)
                                    type = 2;
                            }
                        }
                        if (type == 3)
                            PushBlock(type, pos - 1, j, board, board[pos - 1][j]);
                        else
                            PushBlock(type, pos, j, board, board[pos][j]);
                    }
                }
                break;
            }
        }
    }
    int pushLine = 0;
    for (int i = 4; i < 6; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j])
            {
                pushLine = 6 - i;
                break;
            }
        }
        if (pushLine)
        {
            for (int ii = 9; ii >= 6; --ii)
                for (int jj = 0; jj < 4; ++jj)
                    board[ii][jj] = board[ii - pushLine][jj];
            for (int ii = 4; ii < 6; ++ii)
                for (int jj = 0; jj < 4; ++jj)
                    board[ii][jj] = 0;

            break;
        }
    }

    return line;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int board[2][10][4] = { 0, };
    int line = 0;
    int N;
    cin >> N;
    while (N--)
    {
        int t, y, x;
        cin >> t >> y >> x;
        int bt = t;
        if (t == 2)
            bt = 3;
        else if (t == 3)
            bt = 2;
        int by = x;
        int bx = y;

        line += Push(t, y, x, board[0], N + 1);
        line += Push(bt, by, bx, board[1], N + 1);
    }
    int cnt = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 6; j < 10; ++j)
            for (int k = 0; k < 4; ++k)
                if (board[i][j][k])
                    ++cnt;
    
    cout << line << '\n' << cnt;

    return 0;
}