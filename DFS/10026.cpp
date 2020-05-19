#include <iostream>
#include <cstring>

using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int N;
bool visited[101][101];
char board[101][101];

void Dfs(int x, int y, int c)
{
    visited[y][x] = true;
    if (board[y][x] == 'G')
        board[y][x] = 'R';
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        if (visited[ny][nx] == true)
            continue;
        if (board[ny][nx] == c)
            Dfs(nx, ny, c);
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
            
    int nonBlind = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (visited[i][j] == false)
            {
                ++nonBlind;
                Dfs(j, i, board[i][j]);
            }
        }
    }
    memset(visited, false, sizeof(visited));
    int blind = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (visited[i][j] == false)
            {
                ++blind;
                Dfs(j, i, board[i][j]);
            }
        }
    }
    cout << nonBlind << ' ' << blind;
    
    return 0;
}