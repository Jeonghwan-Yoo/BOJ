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
    
    int M, N;
    cin >> M >> N;
    vector<vector<int> > board(N, vector<int>(M));
    queue<pair<int, int> > q;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                q.emplace(j, i);
            else if (board[i][j] == 0)
                ++cnt;
        }
    }

    int day = 0;
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        if (day < board[cy][cx])
            day = board[cy][cx];
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
            
            if (board[ny][nx] == 0)
            {
                --cnt;
                board[ny][nx] = board[cy][cx] + 1;
                q.emplace(nx, ny);
            }
        }
    }
    if (cnt == 0)
        cout << day - 1;
    else
        cout << -1;

    return 0;
}