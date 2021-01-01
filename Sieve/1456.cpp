#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define MAX_N 10'000'000

bool sieve[MAX_N + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> prime;
    sieve[0] = sieve[1] = true;
    prime.emplace_back(2);
    for (long long i = 3; i <= MAX_N; i += 2)
    {
        if (!sieve[i])
        {
            prime.emplace_back(i);
            for (long long j = i * i; j <= MAX_N; j += i << 1)
                sieve[j] = true;
        }
    }
    int sz = (int)prime.size();

    long long A, B;
    cin >> A >> B;
    int cnt = 0;
    for (int i = 0; i < sz; ++i)
    {
        long long almost = prime[i] * prime[i];
        while (almost <= B)
        {
            if (A <= almost)
                ++cnt;
            if (almost > 1e14 / prime[i])
                break;
            almost *= prime[i];
        }
    }
    cout << cnt;

    return 0;
}