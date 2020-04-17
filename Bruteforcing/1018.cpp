#include <iostream>

using namespace std;

char board[51][51];
int N, M;

const char chess[8][9] = 
{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

int FindChess(int r, int c)
{
    int cnt = 0;
    for (int i = r; i < r + 8; ++i)
    {
        for (int j = c; j < c + 8; ++j)
        {
            if (chess[i - r][j - c] != board[i][j])
            {
                ++cnt;
            }
        }
    }
    if (cnt > 32)
        cnt = 64 - cnt;

    return cnt; 
}

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
    int minPaint = 64;
    for (int i = 0; i <= N - 8; ++i)
    {
        for (int j = 0; j <= M - 8; ++j)
        {
            int paint = FindChess(i, j);
            if (paint < minPaint)
                minPaint = paint;
        }
    }
    cout << minPaint;

    return 0;
}