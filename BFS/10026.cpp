#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

int N;

int Normal(vector<vector<char>> board)
{
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j])
            {
                ++cnt;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (!q.empty())
                {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();
                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int ny = cy + dy[dir];
                        int nx = cx + dx[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;

                        if (board[ny][nx] != NULL && board[ny][nx] == board[cy][cx])
                            q.emplace(ny, nx);
                    }
                    board[cy][cx] = NULL;
                }
            }
        }
    }
    
    return cnt;
}

int Weakness(vector<vector<char>> board)
{
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j])
            {
                ++cnt;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (!q.empty())
                {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();
                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int ny = cy + dy[dir];
                        int nx = cx + dx[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;
                            
                        if (board[ny][nx] != NULL && (board[ny][nx] == board[cy][cx] || (board[ny][nx] == 'R' && board[cy][cx] == 'G') || ( board[ny][nx] == 'G' && board[cy][cx] == 'R')))
                            q.emplace(ny, nx);
                    }
                    board[cy][cx] = NULL;
                }
            }
        }
    }
    
    return cnt;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    vector<vector<char>> board(N, vector<char>(N + 1));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    
    cout << Normal(board) << '\n';
    cout << Weakness(board);

    return 0;
}