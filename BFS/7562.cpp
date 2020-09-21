#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int constexpr dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int constexpr dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

struct Pos
{
    int x, y, cnt;
    Pos(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--)
    {
        int l;
        cin >> l;
        vector<vector<int>> board(l, vector<int>(l));
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        queue<Pos> q;
        board[sy][sx] = 1;
        q.emplace(sx ,sy, 0);
        while (!q.empty())
        {
            int cx = q.front().x;
            int cy = q.front().y;
            int ccnt = q.front().cnt;
            q.pop();

            if (cx == ex && cy == ey)
            {
                cout << ccnt << '\n';
                break;
            }
            
            for (int dir = 0; dir < 8; ++dir)
            {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                int ncnt = ccnt + 1;
                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue;
                
                if (!board[ny][nx])
                {
                    board[ny][nx] = 1;
                    q.emplace(nx, ny, ncnt);
                }
            }
        }
    }

    return 0;
}