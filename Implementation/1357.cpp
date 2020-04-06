#include <iostream>

using namespace std;

int Rev(int val)
{
    int tmp = val;
    int ret = 0;
    while (tmp)
    {
        ret *= 10;
        ret += tmp % 10;
        tmp /= 10;
    }
    cout << ret << '\n';
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int X, Y;
    cin >> X >> Y;
    cout << Rev(Rev(X) + Rev(Y));
    return 0;
}