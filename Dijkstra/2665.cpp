#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 2'500

int constexpr dy[4] = { -1, 0, 1, 0 };
int constexpr dx[4] = { 0, 1, 0, -1 };

int N;

void Dijkstra(int y, int x, vector<vector<int>> &dp, vector<vector<int>> const &board)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.emplace(0, make_pair(y, x));
    dp[y][x] = 0;
    while (!pq.empty())
    {
        int cy = pq.top().second.first;
        int cx = pq.top().second.second;
        pq.pop();
        if (cy == N - 1 && cx == N - 1)
            return;
        for (int d = 0; d < 4; ++d)
        {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            int nw = dp[cy][cx] + !board[ny][nx];
            if (dp[ny][nx] > nw)
            {
                dp[ny][nx] = nw;
                pq.emplace(-nw, make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    char c;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> c;
            board[i][j] = c - '0';
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, INF));
    Dijkstra(0, 0, dp, board);
    cout << dp[N - 1][N - 1];

    return 0;
}