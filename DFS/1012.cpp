#include <iostream>

using namespace std;

const int dx[4] = { 0, 1, 0 ,-1 };
const int dy[4] = { -1, 0, 1, 0 };

int N, M;

void dfs(int r, int c, bool (&cabbage)[50][50])
{
    for (int dir = 0; dir < 4; ++dir)
    {
        int nextR = r + dy[dir];
        int nextC = c + dx[dir];
        if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M)
        {
            continue;
        }
        if (cabbage[nextR][nextC] == true)
        {
            cabbage[nextR][nextC] = false;
            dfs(nextR, nextC, cabbage);
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int K;
        cin >> M >> N >> K;
        bool cabbage[50][50] = { false, };
        for (int k = 0; k < K; ++k)
        {
            int x, y;
            cin >> x >> y;
            cabbage[y][x] = true;
        }
        int worm = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (cabbage[i][j] == true)
                {
                    ++worm;
                    dfs(i, j, cabbage);
                }

            }
        }
        cout << worm << '\n';
    }
    return 0;
}