#include <iostream>
#include <cmath>

using namespace std;

char board[9][10];
int N, M;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j]; 
        }
    }
    int maxNum = -1;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            for (int dy = -N; dy <= N; ++dy)
            {
                for (int dx = -M; dx <= M; ++dx)
                {
                    if (dx == 0 && dy == 0)
                    {
                        continue;
                    }
                    int num = board[y][x] - '0';
                    int nextX = x;
                    int nextY = y;
                    while (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N)
                    {
                        int tmp = sqrt(num);
                        if (tmp * tmp == num)
                        {
                            if (num > maxNum)
                                maxNum = num;
                        }
                        num *= 10;
                        nextX += dx;
                        nextY += dy;
                        num += board[nextY][nextX] - '0';
                    }
                }
            }
        }
    }
    cout << maxNum;

    return 0;
}