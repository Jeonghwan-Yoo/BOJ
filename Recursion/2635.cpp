#include <iostream>

using namespace std;

int Make(int cur, int prev, int cnt)
{
    int val = prev - cur;
    if (val < 0)
    {
        return cnt; 
    }
    return Make(val, cur, cnt + 1);
}

void Print(int cur, int prev)
{
    cout << prev << ' ';
    int val = prev - cur;
    if (val < 0)
    {
        cout << cur;
        return;
    }
    Print(val, cur);
}

int main()
{
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    int maxIdx = 0;
    int maxLen = 0;
    for (int i = (N >> 1); i <= N; ++i)
    {
        int ret = Make(i, N, 2);
        if (ret > maxLen)
        {
            maxLen = ret;
            maxIdx = i;
        }
    }
    cout << maxLen << '\n';
    Print(maxIdx, N);
    return 0;
}