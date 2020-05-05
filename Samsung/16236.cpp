#include <iostream>
#include <queue>

using namespace std;

int board[21][21];
int N;

struct Pos
{
    int x, y, dist;
    bool operator<(const Pos &a) const
    {
        if (y == a.y && dist == a.dist)
            return (x > a.x);
        if (dist == a.dist)
            return (y > a.y);
        return (dist > a.dist);
    }
};
struct Shark
{
    int x, y;
    int sz = 2;
    int eat = 0;
};
Shark shark;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                shark.x = j;
                shark.y = i;
                board[i][j] = 0;
            }
        }
    }
    int time = 0;
    while (1)
    {
        queue<Pos> q;
        priority_queue<Pos> fish;
        bool visited[21][21] = { false, };
        q.push({ shark.x, shark.y, 0 });
        visited[shark.y][shark.x] = true;
        while (!q.empty())
        {
            int curX = q.front().x;
            int curY = q.front().y;
            int curD = q.front().dist;
            q.pop();
            if (fish.size() != 0 && fish.top().dist != curD)
                break;
            if (board[curY][curX] != 0 && board[curY][curX] < shark.sz)
                fish.push({ curX, curY, curD });
            for (int dir = 0; dir < 4; ++dir)
            {
                int nxtX = curX + dx[dir];
                int nxtY = curY + dy[dir];
                int nxtD = curD + 1;
                if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= N)
                    continue;
                if (visited[nxtY][nxtX] == true)
                    continue;
                if (board[nxtY][nxtX] > shark.sz)
                    continue;
                visited[nxtY][nxtX] = true;
                q.push({ nxtX, nxtY, nxtD });
            }
        }
        if (fish.size() == 0)
            break;
        else
        {
            int fx = fish.top().x;
            int fy = fish.top().y;
            int fd = fish.top().dist;
            board[fy][fx] = 0;
            shark.x = fx;
            shark.y = fy;
            ++shark.eat;
            if (shark.eat == shark.sz)
            {
                ++shark.sz;
                shark.eat = 0;
            }
            time += fd;
        }
    }
    cout << time;

    return 0;
}