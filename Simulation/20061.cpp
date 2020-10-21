#include <iostream>
#include <algorithm>

using namespace std;

void MoveDown(int posY, int num, int board[][4])
{
    for (int i = posY; i >= 4; --i)
    {
        for (int j = 0; j < 4; ++j)
        {
            board[i][j] = board[i - num][j];
            board[i - num][j] = 0;
        }
    }
}

void RemoveLine(int posY, int board[][4])
{
    for (int i = 0; i < 4; ++i)
        board[posY][i] = 0;
}

int LineCheck(int board[][4])
{
    int ret = 0;
    for (int i = 6; i < 10; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < 4; ++j)
            if (board[i][j])
                ++cnt;
        
        if (cnt == 4)
        {
            RemoveLine(i, board);
            MoveDown(i, 1, board);
            ret += 1 + LineCheck(board);
        }
    }

    return ret;
}

void LightPartCheck(int board[][4])
{
    for (int i = 4; i < 6; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j])
            {
                MoveDown(9, 6 - i, board);
                return;
            }
        }
    }
}

int Push(int type, int posY, int posX, int board[][4], int idx)
{
    int ret = 0;
    if (type == 1)
    {
        int pos = posY;
        while (pos < 10 && board[pos][posX] == 0)
            ++pos;
        --pos;
        board[pos][posX] = idx;
    }
    else if (type == 2)
    {
        int pos = posY;
        while (pos < 10 && board[pos][posX] == 0 && board[pos][posX + 1] == 0)
            ++pos;
        --pos;
        board[pos][posX] = board[pos][posX + 1] = idx;
    }
    else if (type == 3)
    {
        int pos = posY + 1;
        while (pos < 10 && board[pos][posX] == 0)
            ++pos;
        --pos;
        board[pos][posX] = board[pos - 1][posX] = idx;
    }
    ret += LineCheck(board);
    LightPartCheck(board);

    return ret;
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
    for (int i = 1; i <= N; ++i)
    {
        int t, y, x;
        cin >> t >> y >> x;
        int bt = t;
        if (t == 3)
            bt = 2;
        else if (t == 2)
            bt = 3;
        line += Push(t, y, x, board[0], i);
        line += Push(bt, x, y, board[1], i);
    }
    int cnt = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 0; k < 4; ++k)
                if (board[i][j][k])
                    ++cnt;
    
    cout << line << '\n' << cnt;

    return 0;
}