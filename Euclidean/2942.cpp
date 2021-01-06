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

    int R, G;
    cin >> R >> G;
    int gcd = Gcd(R, G);
    for (int i = 1; i * i <= gcd; ++i)
    {
        if (gcd % i == 0)
        {
            cout << i << ' ' << R / i << ' ' << G / i << '\n';
            if (i * i != gcd)
            {
                int j = gcd / i;
                cout << j << ' ' << R / j << ' ' << G / j << '\n';
            }
        }
    }

    return 0;
}