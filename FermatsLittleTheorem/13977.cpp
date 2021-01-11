#include <iostream>

using namespace std;

#define MAX_N 4'000'000
#define MOD (int)(1e9 + 7)

long long fac[MAX_N + 1];

int ModPow(long long a, int n)
{
    if (n == 0)
        return 1;
    
    if (n & 1)
        return a * ModPow(a, n - 1) % MOD;
    return ModPow(a * a % MOD, n >> 1);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0] = 1;
    for (int i = 1; i <= MAX_N; ++i)
        fac[i] = fac[i - 1] * i % MOD;

    int M;
    cin >> M;
    while (M--)
    {
        int N, K;
        cin >> N >> K;
        cout << fac[N] * ModPow(fac[K] * fac[N - K] % MOD, MOD - 2) % MOD << '\n';
    }

    return 0;
}