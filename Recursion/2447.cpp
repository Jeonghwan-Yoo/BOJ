#include <iostream>

using namespace std;

char star[2187][2187];
int N;

void makeStar(int r, int c, int n)
{
    if (n == 1)
    {
        star[r][c] = '*';
        return;
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == j && i == 1)
                continue;
            makeStar(r + i * n / 3, c + j * n / 3, n / 3);
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            star[i][j] = ' ';
        }
    }
    makeStar(0, 0, N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << star[i][j];
        }
        cout << '\n';
    }
    return 0;
}
