#include <iostream>

using namespace std;

#define MOD (int)(1e9 + 7)

long long ModPow(long long a, int n)
{
    if (n == 0)
        return 1ll;
    
    if (n & 1)
        return a * ModPow(a, n - 1) % MOD;
    return ModPow(a * a % MOD, n >> 1);
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
        res += S * ModPow(N, MOD - 2);
        res %= MOD;
    }
    cout << res;

    return 0;
}