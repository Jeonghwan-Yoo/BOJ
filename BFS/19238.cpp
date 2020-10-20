#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 500

int constexpr dy[4] = { -1, 0, 1, 0 };
int constexpr dx[4] = { 0, 1, 0, -1 };

struct Taxi
{
    int sy, sx, fuel;
};

struct Customer
{
    int ey, ex;
};

int N, M;

int FindCustomer(Taxi &taxi, vector<Customer> &customer, vector<vector<int>> &board)
{
    int minDist = INF;
    vector<pair<int, int>> candidate;
    vector<vector<int>> visited(N, vector<int>(N));
    queue<pair<int, int>> q;
    q.emplace(taxi.sy, taxi.sx);
    visited[taxi.sy][taxi.sx] = 1;
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if (board[cy][cx] >= 2 && visited[cy][cx] - 1 <= minDist)
        {
            minDist = visited[cy][cx] - 1;
            candidate.emplace_back(cy, cx);
        }

        for (int d = 0; d < 4; ++d)
        {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[ny][nx] == 1 || visited[ny][nx])
                continue;

            visited[ny][nx] = visited[cy][cx] + 1;
            if (candidate.empty())
                q.emplace(ny, nx);
        }
    }

    if (candidate.empty())
        return 0;
    if (minDist > taxi.fuel)
    {
        taxi.fuel = -1;
        return -1;
    }

    sort(candidate.begin(), candidate.end());
    taxi.sy = candidate[0].first;
    taxi.sx = candidate[0].second;
    taxi.fuel -= minDist;
    return board[candidate[0].first][candidate[0].second];
}

void FindDestination(int idx, Taxi &taxi, vector<Customer> &customer, vector<vector<int>> &board)
{
    int dist = INF;
    int ey = customer[idx].ey;
    int ex = customer[idx].ex;
    vector<vector<int>> visited(N, vector<int>(N));
    queue<pair<int, int>> q;
    q.emplace(taxi.sy, taxi.sx);
    visited[taxi.sy][taxi.sx] = 1;
    while (!q.empty())
    {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        if (cy == ey && cx == ex)
        {
            dist = visited[cy][cx] - 1;
            break;
        }

        for (int d = 0; d < 4; ++d)
        {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[ny][nx] == 1 || visited[ny][nx])
                continue;

            visited[ny][nx] = visited[cy][cx] + 1;
            q.emplace(ny, nx);
        }
    }
    if (dist == INF || dist > taxi.fuel)
        taxi.fuel = -1;
    else
    {
        taxi.fuel += dist;
        board[taxi.sy][taxi.sx] = 0;
        taxi.sy = ey;
        taxi.sx = ex;
    }
}

bool CheckLeft(vector<vector<int>> &board)
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] >= 2)
                return 1;

    return 0;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Taxi taxi;
    cin >> N >> M >> taxi.fuel;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    cin >> taxi.sy >> taxi.sx;
    --taxi.sy;
    --taxi.sx;
    vector<Customer> customer(M + 2);
    for (int i = 0; i < M; ++i)
    {
        int sy, sx, ey, ex;
        cin >> sy >> sx >> ey >> ex;
        --sy;
        --sx;
        --ey;
        --ex;
        board[sy][sx] = i + 2;
        customer[i + 2] = { ey, ex };
    }
    
    while (taxi.fuel >= 0)
    {
        int idx = FindCustomer(taxi, customer, board);
        if (idx <= 0)
            break;
        FindDestination(idx, taxi, customer, board);
    }
    bool check = CheckLeft(board);
    if (check)
        taxi.fuel = -1;

    cout << taxi.fuel;

    return 0;
}