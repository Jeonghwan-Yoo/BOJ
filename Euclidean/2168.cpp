#include <iostream>

using namespace std;

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    int gcd = Gcd(x, y);
    cout << (long long)(x / gcd + y / gcd - 1) * gcd;

    return 0;
}