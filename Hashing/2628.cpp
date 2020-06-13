#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    vector<int> vx(x + 1);
    vector<int> vy(y + 1);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int d, num;
        cin >> d >> num;
        if (d == 0)
            vy[num] = 1;
        else if (d == 1)
            vx[num] = 1;
    }
    int maxX = 0;
    int prev = 0;
    for (int i = 0; i <= x; ++i)
    {
        if (vx[i] == 1 || i == x)
        {
            maxX = max(maxX, i - prev);
            prev = i;
        }
    }
    int maxY = 0;
    prev = 0;
    for (int i = 0; i <= y; ++i)
    {
        if (vy[i] == 1 || i == y)
        {
            maxY = max(maxY, i - prev);
            prev = i;
        }
    }

    cout << maxX * maxY;

    return 0;
}