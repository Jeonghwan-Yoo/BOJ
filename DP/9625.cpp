#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    int a = 1;
    int b = 0;
    for (int i = 0; i < K; ++i)
    {
        int tmp = b;
        b += a;
        a = tmp;
    }
    cout << a << ' ' << b;

    return 0;
}