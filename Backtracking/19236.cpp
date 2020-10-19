#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int constexpr dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int constexpr dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int maxSum;

struct Shark
{
    int y, x, d;
    int sum;
};

void Dfs(Shark &shark, vector<pair<int, int>> &fishPos, pair<int, int> board[4][4])
{
    for (int i = 1; i <= 16; ++i)
    {
        int fy = fishPos[i].first;
        int fx = fishPos[i].second;
        if (fx == -1 && fy == -1)
            continue;

        int ny = fy + dy[board[fy][fx].second];
        int nx = fx + dx[board[fy][fx].second];
        while (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || (shark.y == ny && shark.x == nx))
        {
            board[fy][fx].second = (board[fy][fx].second + 1) & 7;
            nx = fx + dx[board[fy][fx].second];
            ny = fy + dy[board[fy][fx].second];
        }

        fishPos[board[fy][fx].first] = { ny, nx };
        fishPos[board[ny][nx].first] = { fy, fx };
        swap(board[fy][fx], board[ny][nx]);
    }

    Shark curShark(shark);
    vector<pair<int, int>> curFishPos(fishPos.begin(), fishPos.end());
    pair<int, int> curBoard[4][4];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            curBoard[i][j] = board[i][j];

    int cnt = 0;
    bool finished = true;
    for (int i = 1; i < 4; ++i)
    {
        int nx = shark.x + i * dx[shark.d];
        int ny = shark.y + i * dy[shark.d];
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || board[ny][nx].first == 0)
            continue;

        shark.x = nx;
        shark.y = ny;
        shark.d = board[ny][nx].second;
        shark.sum += board[ny][nx].first;
        fishPos[board[ny][nx].first] = { -1, -1 };
        board[ny][nx] = { 0, 0 };
        Dfs(shark, fishPos, board);
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                board[j][k] = curBoard[j][k];
        for (int j = 1; j <= 16; ++j)
            fishPos[j] = curFishPos[j];
        shark = curShark;
        finished = false;
    }
    if (finished)
        maxSum = max(maxSum, shark.sum);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> board[4][4];
    vector<pair<int, int>> fishPos(17);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int a, b;
            cin >> a >> b;
            board[i][j] = { a, b - 1 };
            fishPos[a] = { i, j };
        }
    }
    Shark shark;
    shark.x = 0;
    shark.y = 0;
    shark.d = board[0][0].second;
    shark.sum = board[0][0].first;
    fishPos[board[0][0].first] = { -1, -1 };
    board[0][0] = { 0, 0 };
    Dfs(shark, fishPos, board);
    cout << maxSum;

    return 0;
}