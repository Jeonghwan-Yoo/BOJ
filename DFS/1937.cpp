#include <iostream>
#include <algorithm>

using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int N;
int board[501][501];
int dp[501][501];

int Dfs(int x, int y)
{
    int &ret = dp[y][x];
    if (ret != 0)
        return ret;
    ret = 1;
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (board[ny][nx] > board[y][x])
            ret = max(ret, 1 + Dfs(nx, ny));
    }
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    
    int maxVal = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            maxVal = max(maxVal, Dfs(i, j));
    cout << maxVal;
    
    return 0;
}