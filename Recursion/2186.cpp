#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N, M, K;
char board[100][100];
int dp[100][100][80];
string target;
int cnt = 0;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int findByDFS(int r, int c, int sz)
{
    if (dp[r][c][sz] != -1)
    {
        return dp[r][c][sz];
    }
    if (target.size() <= sz)
    {
        return 1;
    }
    dp[r][c][sz] = 0;
    for (int dir = 0; dir < 4; ++dir)
    {
        for (int k = 1; k <= K; ++k)
        {
            int nextX = c + dx[dir] * k;
            int nextY = r + dy[dir] * k;
            if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
            {
                break;
            }
            if (board[nextY][nextX] == target[sz])
            {
                dp[r][c][sz] += findByDFS(nextY, nextX, sz + 1);
            }
        }
    }
    return dp[r][c][sz];
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }
    cin >> target;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == target[0])
            {
                cnt += findByDFS(i, j, 1);
            }
        }
    }
    cout << cnt;

    return 0;
}