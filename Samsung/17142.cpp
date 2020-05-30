#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define INF 10'000

constexpr int dx[4] = { 0, 1, 0, -1 };
constexpr int dy[4] = { -1, 0, 1, 0 };

int N, M;
int board[51][51];
int init[51][51];
vector<pair<int, int> > virus;

int minAge = INF;

struct Virus
{
    int x, y;
    int age;
};

void Expand(vector<pair<int, int> > &select)
{
    queue<Virus> q;
    for (int i = 0; i < (int)select.size(); ++i)
        q.push({ select[i].first, select[i].second, 2 });
    
    int maxAge = 2;
    while (!q.empty())
    {
        int curX = q.front().x;
        int curY = q.front().y;
        int curA = q.front().age;
        q.pop();
        if (board[curY][curX] >= 2 && board[curY][curX] != INF)
            continue;
        if (board[curY][curX] != INF)
            maxAge = max(maxAge, curA);
        board[curY][curX] = curA;
        for (int dir = 0; dir < 4; ++dir)
        {
            int nextX = curX + dx[dir];
            int nextY = curY + dy[dir];
            int nextA = curA + 1;
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
                continue;
            if (board[nextY][nextX] == 0 || board[nextY][nextX] == INF)
                q.push({ nextX, nextY, nextA });
        }
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] == 0)
                return;

    minAge = min(minAge, maxAge - 2);
}

void Select(vector<pair<int, int> > &select, int idx)
{
    if (idx > (int)virus.size())
        return;
    if ((int)select.size() >= M)
    {
        Expand(select);
        memcpy(board, init, sizeof(init));
        return;
    }
    Select(select, idx + 1);
    select.emplace_back(virus[idx]);
    Select(select, idx + 1);
    select.pop_back();
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            init[i][j] = board[i][j];
            if (board[i][j] == 2)
            {
                virus.emplace_back(j, i);
                board[i][j] = INF;
                init[i][j] = INF;
            }
        }
    }
    vector<pair<int, int> > select;
    Select(select, 0);
    if (minAge == INF)
        minAge =-1;
    cout << minAge;

    return 0;
}