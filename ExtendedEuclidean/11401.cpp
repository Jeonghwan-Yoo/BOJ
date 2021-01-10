#include <iostream>

using namespace std;

#define MAX_N 4'000'000
#define MOD (int)(1e9 + 7)

long long fac[MAX_N + 1];

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

    int N, K;
    cin >> N >> K;
    fac[0] = 1;
    for (int i = 1; i <= N; ++i)
        fac[i] = fac[i - 1] * i % MOD;
    
    int x, y;
    long long A = fac[N];
    ExtGcd(fac[K] * fac[N - K] % MOD, MOD, x, y);
    int res = A * x % MOD;
    if (res < 0)
        res += MOD;
    cout << res;
    
    return 0;
}