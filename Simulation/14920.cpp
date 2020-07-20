#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int cnt = 1;
    while (n != 1)
    {
        ++cnt;
        if ((n & 1) == 0)
            n >>= 1;
        else
            n = 3 * n + 1;
    }
    cout << cnt;

    return 0;
}