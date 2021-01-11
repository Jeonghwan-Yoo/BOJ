#include <iostream>

using namespace std;

#define MOD (int)(1e9 + 7)

long long ExtGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    long long gcd = ExtGcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long res = 0ll;
    int M;
    cin >> M;
    while (M--)
    {
        int N, S;
        cin >> N >> S;
        int x, y;
        ExtGcd(N, MOD, x, y);
        int tmp = (long long)S * x % MOD;
        if (tmp < 0)
            tmp += MOD;
        res += tmp;
        res %= MOD;
    }
    cout << res;

    return 0;
}