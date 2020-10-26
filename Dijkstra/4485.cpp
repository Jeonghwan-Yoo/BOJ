#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 10'000

int constexpr dy[4] = { -1, 0, 1, 0 };
int constexpr dx[4] = { 0, 1, 0, -1 };

int N;

void Dijkstra(int y, int x, vector<vector<int>> const &board, vector<vector<int>> &dp)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.emplace(-board[y][x], make_pair(y, x));
    dp[y][x] = board[y][x];
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
            if (dp[ny][nx] > dp[cy][cx] + board[ny][nx])
            {
                dp[ny][nx] = dp[cy][cx] + board[ny][nx];
                pq.emplace(-dp[ny][nx], make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    while (cin >> N)
    {
        if (N == 0)
            break;
        ++n;
        vector<vector<int>> board(N, vector<int>(N));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> board[i][j];
        
        vector<vector<int>> dp(N, vector<int>(N, INF));
        Dijkstra(0, 0, board, dp);
        cout << "Problem " << n << ": " << dp[N - 1][N - 1] << '\n';
    }

    return 0;
}