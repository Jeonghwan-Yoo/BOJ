#include <iostream>
#include <algorithm>

using namespace std;

int board[701][701];
int boundary[1401];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            board[i][j] = 1;

    int num0, num1, num2;
    while (N--)
    {
        cin >> num0 >> num1 >> num2;
        ++boundary[num0];
        ++boundary[num0 + num1];
    }
    for (int i = 1; i < (M << 1); ++i)
        boundary[i] += boundary[i - 1];

    int pos = 0;
    for (int i = M - 1; i >= 0; --i)
    {
        board[i][0] += boundary[pos];
        ++pos;
    }
    for (int i = 1; i < M; ++i)
    {
        board[0][i] += boundary[pos];
        ++pos;
    }
    for (int i = 1; i < M; ++i)
    {
        board[i][i] = board[i - 1][i];
        for (int j = i + 1; j < M; ++j)
            board[j][i] = board[j - 1][i];
        for (int j = i + 1; j < M; ++j)
            board[i][j] = board[i - 1][j];
    }
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}