#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1'000'000

bool sieve[MAX_N + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> prime;
    sieve[0] = sieve[1] = true;
    for (long long i = 2; i <= MAX_N; ++i)
    {
        if (!sieve[i])
        {
            prime.emplace_back(i);
            for (long long j = i * i; j <= MAX_N; j += i)
                sieve[j] = true;
        }
    }

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int cnt = 0;
        int N2 = N >> 1;
        for (int i = 0; prime[i] <= N2; ++i)
            if (!sieve[prime[i]] && !sieve[N - prime[i]])
                ++cnt;
        cout << cnt << '\n';
    }

    return 0;
}