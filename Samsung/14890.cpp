#include <iostream>

using namespace std;

int N, L;

int board[100][100];
int road[100];
int cnt = 0;

void check()
{
    int bridge = -1;
    for (int i = 0; i < N - 1; ++i)
    {
        if (road[i + 1] < road[i])
        {
            if (road[i] - road[i + 1] == 1)
            {
                for (int l = 1; l < L; ++l)
                {
                    if (i + l >= N || road[i + 1] != road[i + 1 + l])
                    {
                        return;
                    }
                }
                i += L - 1;
                bridge = i + 1;
            }
            else
            {
                return;
            }
        }
        else if (road[i + 1] > road[i])
        {
            if (bridge + L > i)
            {
                return;
            }
            if (road[i + 1] - road[i] == 1)
            {
                for (int l = 1; l < L; ++l)
                {
                    if (i - l < 0 || road[i] != road[i - l])
                    {
                        return;
                    }
                }
                bridge = i;
            }
            else
            {
                return;
            }
        }
    }
    ++cnt;
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N >> L;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            road[j] = board[i][j];
        }
        check();
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            road[j] = board[j][i];
        }
        check();
    }
    cout << cnt;
    return 0;
}