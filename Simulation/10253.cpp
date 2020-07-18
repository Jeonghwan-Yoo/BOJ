#include <iostream>

using namespace std;

int Gcd(int a, int b)
{
    if (a == 0)
        return b;
    return Gcd(b % a, a);
}

int Henry(int a, int b)
{
    int gcd = Gcd(a, b);
    a /= gcd;
    b /= gcd;
    if (a == 1)
        return b;
    
    int mul = ((b / a) + 1);
    int nextB = mul * b;
    int nextA = mul * a - b;
    int lastDivisor = Henry(nextA, nextB);
    return lastDivisor;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    int a, b;
    while (T--)
    {
        cin >> a >> b;
        cout << Henry(a, b) << '\n';
    }

    return 0;
}