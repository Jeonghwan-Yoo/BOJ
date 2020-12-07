#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int inc = 1;
    int num = 9;
    int len = 0;
    int N;
    cin >> N;
    while (N)
    {
        int left = min(num, N);
        len += inc * left;
        N -= left;
        num *= 10;
        ++inc;
    }
    cout << len;

    return 0;
}