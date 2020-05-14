#include <iostream>

using namespace std;

const int dw[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dh[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int w, h;
int board[51][51];

void Dfs(int ch, int cw)
{
    for (int dir = 0; dir < 8; ++dir)
    {
        int nh = ch + dh[dir];
        int nw = cw + dw[dir];
        if (nh < 0 || nh >= h || nw < 0 ||nw >= w)
            continue;
        if (board[nh][nw] == 0)
            continue;
        board[nh][nw] = 0;
        Dfs(nh, nw);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
            break;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin >> board[i][j];
        int cnt = 0;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (board[i][j] == 0)
                    continue;
                ++cnt;
                board[i][j] = 0;
                Dfs(i, j);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}