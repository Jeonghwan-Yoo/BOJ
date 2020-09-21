#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int constexpr dh[6] = { 0, 0, 0, 0, 1, -1 };
int constexpr dy[6] = { -1, 0, 1, 0, 0, 0 };
int constexpr dx[6] = { 0, 1, 0, -1, 0, 0 };

struct Pos
{
    int h, y, x;
    Pos(int h, int y, int x) : h(h), y(y), x(x) {}
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, N, H;
    cin >> M >> N >> H;
    vector<vector<vector<int>>> board(H, vector<vector<int>>(N, vector<int>(M)));
    queue<Pos> q;
    int cnt = 0;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                    q.emplace(i, j, k);
                else if (board[i][j][k] == 0)
                    ++cnt;
            }
        }
    }
    int maxVal = 1;
    while (!q.empty())
    {
        int ch = q.front().h;
        int cy = q.front().y;
        int cx = q.front().x;
        q.pop();

        for (int i = 0; i < 6; ++i)
        {
            int nh = ch + dh[i];
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (nh < 0 || nh >= H || nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;

            if (!board[nh][ny][nx])
            {
                q.emplace(nh, ny, nx);
                --cnt;
                board[nh][ny][nx] = board[ch][cy][cx] + 1;
                if (maxVal < board[nh][ny][nx])
                    maxVal = board[nh][ny][nx];
            }
        }
    }
    cout << (cnt == 0 ? maxVal - 1 : -1);

    return 0;
}