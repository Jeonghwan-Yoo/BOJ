#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int constexpr dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int constexpr dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (1)
    {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        vector<vector<int>> board(h, vector<int>(w));
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin >> board[i][j];
        
        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (board[i][j])
                {
                    ++cnt;
                    board[i][j] = 0;
                    q.emplace(j, i);
                    while (!q.empty())
                    {
                        int cx = q.front().first;
                        int cy = q.front().second;
                        q.pop();

                        for (int dir = 0; dir < 8; ++dir)
                        {
                            int nx = cx + dx[dir];
                            int ny = cy + dy[dir];
                            if (nx < 0 || nx >= w || ny < 0 || ny >= h)
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