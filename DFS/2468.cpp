#include <iostream>
#include <cstring>

using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int N;
int board[101][101];
bool visited[101][101];

void Dfs(int x, int y, int h)
{
    visited[y][x] = true;
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (visited[ny][nx] == false && board[ny][nx] > h)
        {
            Dfs(nx, ny, h);
        }
    }
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
    
    int maxSafe = 0;
    for (int h = 0; h <= 100; ++h)
    {
        memset(visited, false, sizeof(visited));
        int safe = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (visited[i][j] == false && board[i][j] > h)
                {
                    ++safe;
                    Dfs(j, i, h);
                }
            }
        }
        if (maxSafe < safe)
            maxSafe = safe;
    }
    cout << maxSafe;
            
    return 0;
}