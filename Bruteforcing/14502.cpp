#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int constexpr dy[4] = { -1, 0, 1, 0 };
int constexpr dx[4] = { 0, 1, 0, -1 };

int N, M;
int maxVal;
void Extend(int y, int x, vector<vector<int>> &board)
{
    for (int d = 0; d < 4; ++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || board[ny][nx] != 0)
            continue;

        board[ny][nx] = 2;
        Extend(ny, nx, board);
    }
}

int CheckSafeZone(vector<vector<int>> &board)
{
    int val = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!board[i][j])
                ++val;

    return val;
}

void Select(int y, int x, int left, vector<vector<int>> &board, vector<pair<int, int>> &virus)
{
    if (left == 0)
    {
        vector<vector<int>> original(board.begin(), board.end());
        for (int i = 0; i < (int)virus.size(); ++i)
            Extend(virus[i].first, virus[i].second, board);
        maxVal = max(maxVal, CheckSafeZone(board));
        board.assign(original.begin(), original.end());
        return;
    }

    if (x == M)
    {
        ++y;
        x = 0;
    }
    if (y == N)
        return;

    if (board[y][x] == 0)
    {
        board[y][x] = 1;
        Select(y, x + 1, left - 1, board, virus);
        board[y][x] = 0;
    }
    Select(y, x + 1, left, board, virus);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));
    vector<pair<int, int>> virus;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.emplace_back(i, j);
        }
    }
    Select(0, 0, 3, board, virus);
    cout << maxVal;

    return 0;
}