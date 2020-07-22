#include <iostream>

using namespace std;

int constexpr dr[4] = { -1, 0, 1, 0 };
int constexpr dc[4] = { 0, 1, 0, -1 };

char board[11][11];
char after50years[11][11];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> board[i][j];

    int minR = 10;
    int minC = 10;
    int maxR = 0;
    int maxC = 0;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (board[i][j] == '.')
            {
                after50years[i][j] = board[i][j];
                continue;
            }
            int cnt = 0;
            for (int dir = 0; dir < 4; ++dir)
            {
                int adjR = i + dr[dir];
                int adjC = j + dc[dir];
                if (adjR < 0 || adjR >= R || adjC < 0 || adjC >= C || board[adjR][adjC] == '.')
                    ++cnt;
            }
            if (cnt >= 3)
                after50years[i][j] = '.';
            else
            {
                after50years[i][j] = 'X';
                if (minR > i)
                    minR = i;
                if (maxR < i)
                    maxR = i;
                if (minC > j)
                    minC = j;
                if (maxC < j)
                    maxC = j;
            }
        }
    }
    for (int i = minR; i <= maxR; ++i)
    {
        for (int j = minC; j <= maxC; ++j)
            cout << after50years[i][j];
        cout << '\n';
    }

    return 0;
}