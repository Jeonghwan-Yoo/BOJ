#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M)); 
    queue<pair<int, int>> virus;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.emplace(j, i);
        }
    }
    int maxCnt = 0;
    int len = N * M;
    for (int i = 0; i < len; ++i)
    {
        int n1 = i / M;
        int m1 = i % M;
        if (board[n1][m1] != 0)
            continue;

        board[n1][m1] = 1;
        for (int j = i + 1; j < len; ++j)
        {
            int n2 = j / M;
            int m2 = j % M;
            if (board[n2][m2] != 0)
                continue;
            
            board[n2][m2] = 1;
            for (int k = j + 1; k < len; ++k)
            {
                int n3 = k / M;
                int m3 = k % M;
                if (board[n3][m3] != 0)
                    continue;
                
                board[n3][m3] = 1;
                
                vector<vector<int>> tmpBoard(board);
                queue<pair<int, int>> q(virus);
                while (!q.empty())
                {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    
                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                            continue;

                        if (tmpBoard[ny][nx] == 0)
                        {
                            tmpBoard[ny][nx] = 2;
                            q.emplace(nx, ny);
                        }
                    }
                }
                int cnt = 0;
                for (int r = 0; r < N; ++r)
                    for (int c = 0; c < M; ++c)
                        if (!tmpBoard[r][c])
                            ++cnt;
                if (maxCnt < cnt)
                    maxCnt = cnt;

                board[n3][m3] = 0;
            }
            board[n2][m2] = 0;
        }
        board[n1][m1] = 0;
    }
    cout << maxCnt;

    return 0;
}