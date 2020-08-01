#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

enum State
{
    Lake = 0,
    Ground = 1,
    Able = 2,
    Green = 3,
    Red = 4,
    Flower = 5,
};

int N, M, G, R;
int initBoard[51][51];
int board[51][51];
vector<pair<int, int> > green;
vector<pair<int, int> > red;

int Grow()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            board[i][j] = initBoard[i][j];

    int cnt = 0;
    queue<pair<int, int> > q;
    for (int i = 0; i < (int)green.size(); ++i)
    {
        board[green[i].second][green[i].first] = State::Green;
        q.emplace(green[i]);
    }
    for (int i = 0; i < (int)red.size(); ++i)
    {
        board[red[i].second][red[i].first] = State::Red;
        q.emplace(red[i]);
    }
    while (!q.empty())
    {
        queue<pair<pair<int, int>, int> > check;
        while (!q.empty())
        {
            int curX = q.front().first;
            int curY = q.front().second;
            int color = board[curY][curX];
            q.pop();
            if (color == State::Flower)
                continue;
            for (int dir = 0; dir < 4; ++dir)
            {
                int nextX = curX + dx[dir];
                int nextY = curY + dy[dir];
                if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || board[nextY][nextX] == State::Lake)
                    continue;
                if (board[nextY][nextX] == State::Ground)
                    check.emplace(make_pair(nextX, nextY), color);
            }
        }
        while (!check.empty())
        {
            int nextX = check.front().first.first;
            int nextY = check.front().first.second;
            int color = check.front().second;
            check.pop();
            if (board[nextY][nextX] == State::Ground)
            {
                board[nextY][nextX] = color;
                q.emplace(nextX, nextY);
            }
            else if (board[nextY][nextX] == State::Green)
            {
                if (color == State::Red)
                {
                    board[nextY][nextX] = State::Flower;
                    ++cnt;
                }
            }
            else if (board[nextY][nextX] == State::Red)
            {
                if (color == State::Green)
                {
                    board[nextY][nextX] = State::Flower;
                    ++cnt;
                }
            }
        }
    }
    return cnt;
}

int Select(vector<pair<int, int> > &able, int idx)
{
    if (idx > (int)able.size())
        return 0;

    if ((int)green.size() > G)
        return 0;
    
    if ((int)red.size() > R)
        return 0;

    int maxFlower = 0;
    if ((int)green.size() == G && (int)red.size() == R)
    {
        maxFlower = max(maxFlower, Grow());
        return maxFlower;
    }
    
    if ((int)green.size() < G)
    {
        green.emplace_back(able[idx]);
        maxFlower = max(maxFlower, Select(able, idx + 1));
        green.pop_back();
    }
    if ((int)red.size() < R)
    {
        red.emplace_back(able[idx]);
        maxFlower = max(maxFlower, Select(able, idx + 1));
        red.pop_back();
    }
    maxFlower = max(maxFlower, Select(able, idx + 1));
    return maxFlower;
}

int Gardening(vector<pair<int, int> > &able)
{
    return Select(able, 0);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> G >> R;
    vector<pair<int, int> > able;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> initBoard[i][j];
            if (initBoard[i][j] == State::Able)
            {
                able.emplace_back(j, i);
                initBoard[i][j] = State::Ground;
            }
        }
    }
    cout << Gardening(able);

    return 0;
}