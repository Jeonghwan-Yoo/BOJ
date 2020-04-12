#include <iostream>

using namespace std;

bool board[128][128];
int color[2];

void Divide(int r, int c, int n)
{
    if (n == 1)
    {
        ++color[board[r][c]];
        return;
    }
    int nextN = n >> 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i + r][j + c] != board[r][c])
            {
                Divide(r, c, nextN);
                Divide(r + nextN, c, nextN);
                Divide(r, c + nextN, nextN);
                Divide(r + nextN, c + nextN, nextN);
                return;
            }
        }
    }
    ++color[board[r][c]];
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
    Divide(0, 0, N);
    cout << color[0] << '\n' << color[1];
    return 0;
}