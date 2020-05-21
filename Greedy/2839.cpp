#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int div = N / 5;
    int remainder = (N - div * 5);
    int res = 0;
    while (div >= 0)
    {
        if (remainder % 3 == 0)
        {
            res = div + remainder / 3;
            break;
        }
        remainder += 5;
        --div;
    }
    if (div < 0)
        res = -1;
    cout << res;
    
    return 0;
}