#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int constexpr dx[4] = { 0, 0, -1, 1 };
int constexpr dy[4] = { -1, 1, 0, 0 };

int N, M, K;

struct Shark
{
    int x, y, d;
    int pri[4][4];
};

void Spray(vector<vector<pair<int, int>>> &board, vector<Shark> &shark)
{
    for (int i = 1; i <= M; ++i)
    {
        if (shark[i].x == -1)
            continue;

        int x = shark[i].x;
        int y = shark[i].y;
        board[y][x] = { i, K };
    }
}

void Move(vector<vector<pair<int, int>>> &board, vector<Shark> &shark)
{
    for (int i = 1; i <= M; ++i)
    {
        if (shark[i].x == -1)
            continue;

        int x = shark[i].x;
        int y = shark[i].y;
        int d = shark[i].d;
        int self = -1;
        for (int dir = 0; dir < 4; ++dir)
        {
            int nd = shark[i].pri[d][dir];
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (board[ny][nx].first == 0)
            {
                shark[i].x = nx;
                shark[i].y = ny;
                shark[i].d = nd;
                break;
            }
            else if (board[ny][nx].first == i && self == -1)
                self = nd;
        }

        if (x == shark[i].x && y == shark[i].y)
        {
            shark[i].x = x + dx[self];
            shark[i].y = y + dy[self];
            shark[i].d = self;
        }
    }
}

void Kill(vector<Shark> &shark)
{
    vector<vector<int>> visited(N, vector<int>(N));
    for (int i = 1; i <= M; ++i)
    {
        if (shark[i].x == -1)
            continue;

        if (visited[shark[i].y][shark[i].x])
        {
            shark[i].x = -1;
            continue;
        }

        visited[shark[i].y][shark[i].x] = 1;
    }
}

void Evaporate(vector<vector<pair<int, int>>> &board)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j].first)
            {
                --board[i][j].second;
                if (board[i][j].second == 0)
                    board[i][j].first = 0;
            }
        }
    }
}

bool CheckLeft(vector<Shark> const &shark)
{
    for (int i = 2; i <= M; ++i)
        if (shark[i].x != -1)
            return true;
    return false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    vector<vector<pair<int, int>>> board(N, vector<pair<int, int>>(N));
    vector<Shark> shark(M + 1);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j].first;
            if (board[i][j].first)
            {
                shark[board[i][j].first].x = j;
                shark[board[i][j].first].y = i;
            }
        }
    }
    for (int i = 1; i <= M; ++i)
    {
        cin >> shark[i].d;
        --shark[i].d;
    }
            
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                cin >> shark[i].pri[j][k];
                --shark[i].pri[j][k];
            }
        }
    }
    
    int turn = 0;
    bool check = true;
    while (check && turn <= 1'000)
    {
        ++turn;
        check = false;
        Spray(board, shark);
        Move(board, shark);
        Kill(shark);
        Evaporate(board);
        check = CheckLeft(shark);
    }
    if (turn > 1'000)
        turn = -1;
    
    cout << turn;
            
    return 0;
}