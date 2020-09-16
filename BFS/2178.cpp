#include <iostream>
#include <queue>

using namespace std;

#define INF 10'001

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

struct Pos
{
    int x, y, d;
    Pos(int x, int y, int d) : x(x), y(y), d(d) {}
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > visited(N + 1, vector<int>(M + 1));
    vector<vector<char> > board(N + 1, vector<char>(M + 2));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];

    int minDist = INF;
    queue<Pos> q;
    visited[1][1] = true;
    q.emplace(1, 1, 1);
    while (!q.empty())
    {
        int cx = q.front().x;
        int cy = q.front().y;
        int cd = q.front().d;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i]; 
            int ny = cy + dy[i]; 
            int nd = cd + 1;
            if (nx <= 0 || nx > M || ny <= 0 || ny > N)
                continue;
            if (!visited[ny][nx])
            {
                visited[ny][nx] = 1;
                if (board[ny][nx] == '1')
                {
                    if (nx == M && ny == N)
                    {
                        minDist = nd;
                        break;
                    }
                    q.emplace(nx, ny, nd);
                }
            }
        }
        if (minDist != INF)
            break;
    }  
    cout << minDist;

    return 0;
}