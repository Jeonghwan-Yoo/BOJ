#include <iostream>
#include <cstring>

using namespace std;

constexpr int dx[4] = { 0, 1, 0, -1 };
constexpr int dy[4] = { -1, 0, 1, 0 };

int N, M;
int board[301][301];
int adj[301][301];

void Dfs(int x, int y)
{
    adj[y][x] = 0;
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        if (adj[ny][nx] != -1)
            continue;
        if (board[ny][nx] == 0)
            ++adj[y][x];
        else
            Dfs(nx, ny);
    }
    board[y][x] -= adj[y][x];
    if (board[y][x] < 0)
        board[y][x] = 0;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];

    int year = -1;
    int component = 0;
    while (1)
    {
        component = 0;
        ++year;
        memset(adj, -1, sizeof(adj));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (adj[i][j] == -1 && board[i][j] != 0)
                {
                    ++component;
                    if (component > 1)
                        break;
                    Dfs(j, i);
                }
            }
            if (component > 1)
                break;
        }
        if (component > 1 || component == 0)
            break;
    }
    if (component == 0)
        year = 0;
    cout << year;
    
    return 0;
}