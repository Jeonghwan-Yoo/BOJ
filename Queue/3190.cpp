#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int board[100][100];

const int dr[4] = { -1, 0, 1, 0 };
const int dc[4] = { 0, 1, 0, -1 };

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < K; ++i)
    {
        int r, c;
        cin >> r >> c;
        --r;
        --c;
        board[r][c] = 1;
    }
    int L;
    cin >> L;
    queue<pair<int, int> > change;
    for (int i = 0; i < L; ++i)
    {
        int x;
        char d;
        cin >> x >> d;
        if (d == 'L')
            d = 3;
        else if (d == 'D')
            d = 1;
        change.push({ x + 1, d });
    }
    int time = 0;
    deque<pair<int, int> > cur;
    int dir = 1;
    cur.push_front({ 0, 0 });
    board[0][0] = 2;
    while (1)
    {
        ++time;
        if (!change.empty() && change.front().first == time)
        {
            dir = (dir + change.front().second) & 3;
            change.pop();
        }
        int nextR = cur.front().first + dr[dir];
        int nextC = cur.front().second + dc[dir];
        if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N)
            break;
        if (board[nextR][nextC] == 2)
            break;
        pair<int, int> tmp = cur.back();
        board[cur.back().first][cur.back().second] = 0;
        cur.pop_back();
        cur.push_front({ nextR, nextC });
        if (board[nextR][nextC] == 1)
        {
            board[tmp.first][tmp.second] = 2;
            cur.push_back(tmp);
        }
        board[nextR][nextC] = 2;
    }
    cout << time;
    return 0;
}