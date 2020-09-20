#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, K;
        cin >> M >> N >> K;
        vector<vector<int>> board(N, vector<int>(M));
        for (int i = 0; i < K; ++i)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (board[i][j])
                {
                    ++cnt;
                    queue<pair<int, int>> q;
                    board[i][j] = 0;
                    q.emplace(j, i);
                    while (!q.empty())
                    {
                        int cx = q.front().first;
                        int cy = q.front().second;
                        q.pop();
                        for (int dir = 0; dir < 4; ++dir)
                        {
                            int nx = cx + dx[dir];
                            int ny = cy + dy[dir];
                            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                                continue;
                            if (board[ny][nx])
                            {
                                board[ny][nx] = 0;
                                q.emplace(nx, ny);
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}