#include <iostream>

using namespace std;

int sparse[20][200'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> sparse[0][i];
    for (int i = 1; i < 20; ++i)
        for (int j = 1; j <= m; ++j)
            sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    
    int Q;
    cin >> Q;
    while (Q--)
    {
        int n, x;
        cin >> n >> x;
        int cnt = 0;
        while (n > 0)
        {
            if ((n & 1) != 0)
                x = sparse[cnt][x];
            n >>= 1;
            ++cnt;
        }
        cout << x << '\n';
    }
    return 0;
}