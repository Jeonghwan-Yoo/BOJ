#include <iostream>

using namespace std;

bool IsPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int ModPow(long long a, int n, int p)
{
    if (n == 0)
        return 1;
    
    if (n & 1)
        return a * ModPow(a, n - 1, p) % p;
    return ModPow(a * a % p, n >> 1, p);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1)
    {
        int p, a;
        cin >> p >> a;
        if (p == 0 && a == 0)
            break;

        if (!IsPrime(p) && ModPow(a, p, p) == a)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}