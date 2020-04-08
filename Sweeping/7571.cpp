#include <iostream>
#include <algorithm>

using namespace std;

int r[10001];
int c[10001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int in;
        cin >> in;
        ++r[in];
        cin >> in;
        ++c[in];
    }
    int pr = 0;
    int cnt = 0;
    for (int i = 1; i <= 10000; ++i)
    {
        cnt += r[i];
        if (cnt > (M >> 1))
        {
            pr = i;
            break;
        }
    }
    int pc = 0;
    cnt = 0;
    for (int i = 1; i <= 10000; ++i)
    {
        cnt += c[i];
        if (cnt > (M >> 1))
        {
            pc = i;
            break;
        }
    }
    int dis = 0;
    for (int i = 1; i <= 10000; ++i)
    {
        dis += abs((i - pr) * r[i]) + abs((i - pc) * c[i]);
    }
    cout << dis;
    
    return 0;
}
