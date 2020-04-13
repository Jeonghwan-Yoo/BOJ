#include <iostream>

using namespace std;

bool ladder[10][30];
int N, M, H;
int minCnt = 4;

bool Check()
{
    for (int i = 0; i < N; ++i)
    {
        int pos = i;
        for (int j = 0; j < H; ++j)
        {
            if (ladder[pos][j] == true)
            {
                ++pos;
            }
            else if (pos - 1 >= 0 && ladder[pos - 1][j] == true)
            {
                --pos;
            }
        }
        if (pos != i)
        {
            return false;
        }
    }
    return true;
}

void AddLine(int n, int h, int cnt)
{
    if (cnt > minCnt || cnt > 3)
    {
        return;
    }
    if (Check())
    {
        minCnt = cnt;
        return;
    }
    for (int i = n; i < N; ++i)
    {
        for (int j = h; j < H; ++j)
        {
            if (ladder[i][j] == 0 && ((i - 1 >= 0 && ladder[i - 1][j] == 0) || (i - 1 < 0)) && ((i + 1 < N && ladder[i + 1][j] == 0) || (i + 1 >= N)))
            {
                ladder[i][j] = true;
                AddLine(i, j, cnt + 1);
                ladder[i][j] = false;
            }
        }
        h = 0;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> H;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        ladder[b - 1][a - 1] = 1;
    }
    AddLine(0, 0, 0);
    if (minCnt == 4)
    {
        minCnt = -1;
    }
    cout << minCnt;

    return 0;
}