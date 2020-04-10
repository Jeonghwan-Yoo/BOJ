#include <iostream>

using namespace std;

int board[2187][2187];

int cnt[3];

void Cut(int r, int c, int n)
{
    if (n == 1)
    {
        ++cnt[board[r][c] + 1];
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[r][c] != board[i + r][j + c])
            {
                for (int i = 0; i < 3; ++i)
                {
                    for (int j = 0; j < 3; ++j)
                    {
                        Cut(r + i * (n / 3), c + j * (n / 3), n / 3);
                    }
                }
                return;
            }
        }
    }
    ++cnt[board[r][c] + 1];
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }
    Cut(0, 0, N);
    for (int i = 0; i < 3; ++i)
    {
        cout << cnt[i] << '\n';
    }
    return 0;
}