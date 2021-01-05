#include <iostream>
#include <cmath>

using namespace std;

long long Gcd(long long a, long long b)
{
    if (b == 0ll)
        return a;
    return Gcd(b, a % b);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int gcd, lcm;
    cin >> gcd >> lcm;
    int mul = lcm / gcd;
    for (int i = sqrt(mul); i * i <= mul; --i)
    {
        int j = mul / i;
        if (i * j == mul && Gcd(i, j) == 1)
        {
            cout << gcd * i << ' ' << gcd * j;
            break;
        }
    }
    
    return 0;
}