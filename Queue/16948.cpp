#include <iostream>
#include <queue>

using namespace std;

#define INF 1e9

const int dr[6] = { -2, -2, 0, 0, 2, 2 };
const int dc[6] = { -1, 1, -2, 2, -1, 1 };

struct Night
{
    int r, c;
    int cnt;
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int board[201][201] = { 0, };
    int visited[201][201] = { 0, };
    queue<Night> q;
    visited[r1][c1] = 1;
    q.push({ r1, c1, 0 });
    int move = INF;
    while (!q.empty())
    {
        Night cur = q.front();
        q.pop();
        if (cur.r == r2 && cur.c == c2)
        {
            if (move > cur.cnt)
                move = cur.cnt;
        }
        for (int dir = 0; dir < 6; ++dir)
        {
            int nextR = cur.r + dr[dir];
            int nextC = cur.c + dc[dir];
            int nextCnt = cur.cnt + 1;
            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N)
                continue;
            if (visited[nextR][nextC] == 1)
                continue;
            visited[nextR][nextC] = 1;
            q.push({ nextR, nextC, nextCnt });
        }
    }
    if (move == INF)
        move = -1;
    cout << move;
    return 0;
}