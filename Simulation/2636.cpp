#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

int N, M;
int board[101][101];
bool visited[101][101];
vector<pair<int, int> > c;

void Dfs(int x, int y)
{
    for (int dir = 0; dir < 4; ++dir)
    {
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
        if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
            continue;
        if (visited[nextY][nextX] == false)
        {
            visited[nextY][nextX] = true;
            if (board[nextY][nextX] == 0)
                Dfs(nextX, nextY);
            else
                c.emplace_back(nextX, nextY);
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
    
    int startX = 0;
    int startY = 0;
    visited[startY][startX] = true;
    Dfs(startX, startY);

    int time = 0;
    int prevCnt = (int)c.size();
    while (!c.empty())
    {
        ++time;
        prevCnt = (int)c.size();
        for (int i = 0; i < (int)c.size(); ++i)
        {
            int x = c[i].first;
            int y = c[i].second;
            board[y][x] = 0;
            visited[y][x] = false;
        }
        vector<pair<int, int> > start(c.begin(), c.end());
        c.clear();
        for (int i = 0; i < (int)start.size(); ++i)
        {
            startX = start[i].first;
            startY = start[i].second;
            if (visited[startY][startX] == false)
            {
                visited[startY][startX] = true;
                Dfs(startX, startY);
            }
        }
    }
    cout << time << '\n' << prevCnt;
            
    return 0;
}