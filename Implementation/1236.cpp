#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
char board[50][50];
bool guardX[50];
bool guardY[50];

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'X')
            {
                guardX[j] = true;
                guardY[i] = true;
            }
        }
    }
    int cntX = 0;
    int cntY = 0;
    for (int i = 0; i < N; ++i)
    {
        if (guardY[i] == false)
            ++cntY;
    }
    for (int i = 0; i < M; ++i)
    {
        if (guardX[i] == false)
            ++cntX;
    }
    cout << (cntX >= cntY ? cntX : cntY);    

    return 0;
}