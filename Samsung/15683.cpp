#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int board[8][8];
int N, M;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

struct CCTV
{
    int r, c;
    int type;
    int direction;
    void Change(int dir)
    {
        int nextR = r + dy[dir];
        int nextC = c + dx[dir];
        while (1)
        {
            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M || board[nextR][nextC] == 6)
            {
                break;
            }
            board[nextR][nextC] = 9;
            nextR += dy[dir];
            nextC += dx[dir];
        }
    }
    void Monitor()
    {
        switch(type)
        {
            case 1:
            {
                Change(direction);
                break;
            }
            case 2:
            {
                Change(direction);
                Change((direction + 2) % 4);
                break;
            }
            case 3:
            {
                Change(direction);
                Change((direction + 1) % 4);
                break;
            }
            case 4:
            {
                Change(direction);
                Change((direction + 1) % 4);
                Change((direction + 2) % 4);
                break; 
            }
            case 5:
            {
                Change(direction);
                Change((direction + 1) % 4);
                Change((direction + 2) % 4);
                Change((direction + 3) % 4);
                break;
            }
        }
    }
};

CCTV camera[8];
int minCnt = 64;

void Check()
{
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M;++j)
        {
            if (board[i][j] == 0)
            {
                ++cnt;
            }
        }
    }
    minCnt = min(minCnt, cnt);
}

void Rotate(int n)
{
    for (int i = 0; i < (1 << (n << 1)); ++i)
    {
        int tmp[8][8];
        memcpy(tmp, board, sizeof(board));
        int mask = i;
        for (int j = 0; j < n; ++j)
        {
            camera[j].direction = (mask / (1 << (j << 1)) % 4);
            mask -= camera[j].direction * (1 << j);
            if (camera[j].direction >= 1 && camera[j].type == 5)
            {
                continue;
            }
            if (camera[j].direction >= 2 && camera[j].type == 2)
            {
                continue;
            }
            camera[j].Monitor();
        }
        Check();
        memcpy(board, tmp, sizeof(board));
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    int idx = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] > 0 && board[i][j] < 6)
            {
                camera[idx].r = i;
                camera[idx].c = j;
                camera[idx].type = board[i][j];
                ++idx;
            }
        }
    }
    Rotate(idx);
    cout << minCnt;
    return 0;
}