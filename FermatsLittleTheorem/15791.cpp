#include <iostream>
#include <algorithm>

using namespace std;

#define MOD (int)(1e9 + 7)

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

    int N, M;
    cin >> N >> M;
    M = min(M, N - M);
    long long fromN = 1ll;
    long long from0 = 1ll;
    for (int i = 0; i < M; ++i)
    {
        fromN = fromN * (N - i) % MOD;
        from0 = from0 * (i + 1) % MOD;
    }
    cout << fromN * ModPow(from0, MOD - 2) % MOD;

    return 0;
}