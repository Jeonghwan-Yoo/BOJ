#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100'000

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sieve(MAX_N + 1);
    vector<int> prime;
    sieve[1] = 1;
    for (long long i = 2; i <= MAX_N; ++i)
    {
        if (!sieve[i])
        {
            prime.emplace_back(i);
            for (long long j = i * i; j <= MAX_N; j += i)
                sieve[j] = 1;
        }
    }
    int sz = prime.size();

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        for (int i = 0; i < sz; ++i)
        {
            int cnt = 0;
            while (N % prime[i] == 0)
            {
                ++cnt;
                N /= prime[i];
            }
            if (cnt > 0)
                cout << prime[i] << ' ' << cnt << '\n';
            if (N == 1)
                break;
        }
    }

    return 0;
}