#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cur = 0;
    int maxNum = 0;
    int off;
    int on;
    for (int i = 0; i < 10; ++i)
    {
        cin >> off >> on;
        cur -= off;
        cur += on;
        if (maxNum < cur)
            maxNum = cur;
    }
    cout << maxNum;

    return 0;
}