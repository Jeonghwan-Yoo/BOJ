#include <iostream>

using namespace std;

char star[3 * (1 << 10)][3 * (1 << 11)];

const char line[3][7] = { "  *   ", " * *  ", "***** " };

void makeStar(int r, int c, int n)
{
    if (n == 3)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 6; ++j)
            {
                star[i + r][j + c] = line[i][j];
            }
        }
        return;
    }
    int nextN = n >> 1;
    makeStar(r, c + nextN, nextN);
    makeStar(r + nextN, c, nextN);
    makeStar(r + nextN, c + (nextN << 1), nextN);
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
        for (int j = 0; j < (N << 1); ++j)
        {
            star[i][j] = ' ';
        }
    }
    makeStar(0, 0, N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < (N << 1); ++j)
        {
            cout << star[i][j];
        }
        cout << '\n';
    }
    return 0;
}