#include <iostream>
#include <algorithm>

using namespace std;

long long W, H, f, c, x1, y1, x2, y2;

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;
    long long edge = min(f, W - f);
    long long total = W * H;
    if (edge < x1)
    {
        cout << total - (c + 1) * (x2 - x1) * (y2 - y1);
    }
    else if (edge >= x1 && edge < x2)
    {
        cout << total - (c + 1) * (x2 - x1) * (y2 - y1) - (c + 1) * (edge - x1) * (y2 - y1);
    }
    else if (edge >= x2)
    {
        cout << total - (c + 1) * (x2 - x1) * (y2 - y1) * 2;
    }

    return 0;
}