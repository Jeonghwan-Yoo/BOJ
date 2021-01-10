#include <iostream>
#include <algorithm>

using namespace std;

#define MOD (int)(1e9 + 7)

long long Power(long long a, int n)
{
    if (n == 0)
        return 1ll;
    
    if (n & 1)
        return a * Power(a, n - 1) % MOD;
    return Power(a * a % MOD, n >> 1) % MOD;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    K = min(K, N - K);
    long long fromN = 1ll;
    long long from0 = 1ll;
    for (int i = 0; i < K; ++i)
    {
        fromN = fromN * (N - i) % MOD;
        from0 = from0 * (i + 1) % MOD;
    }

    cout << fromN * Power(from0, MOD - 2) % MOD;
    
    return 0;
}