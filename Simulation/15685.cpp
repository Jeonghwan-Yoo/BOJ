#include <iostream>
#include <vector>

using namespace std;

int board[101][101];
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

void Draw(int x, int y, vector<int> dSet, int curG, int g)
{
    if (curG == g)
    {
        return;
    }
    vector<int> tmp(dSet.rbegin(), dSet.rend());
    int curX = x;
    int curY = y;
    int curLen = tmp.size();
    for (int i = 0; i < curLen; ++i)
    {
        int nextD = (tmp[i] + 1) & 3;
        int nextX = curX + dx[nextD];
        int nextY = curY + dy[nextD];
        board[nextY][nextX] = 1;
        curX = nextX;
        curY = nextY;
        dSet.push_back(nextD);
    }
    Draw(curX, curY, dSet, curG + 1, g);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        board[y][x] = 1;
        board[y + dy[d]][x + dx[d]] = 1;
        vector<int> dSet(1, d); 
        Draw(x + dx[d], y + dy[d], dSet, 0, g);
    }
    int cnt = 0;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j + 1] == 1)
            {
                ++cnt;
            }
        }
    }
    cout << cnt;
    return 0;
}