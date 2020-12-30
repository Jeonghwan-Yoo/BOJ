#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 1'000

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sieve(MAX_N + 1);
    vector<int> prime;
    sieve[0] = sieve[1] = 1;
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
        bool flag = false;
        int K;
        cin >> K;
        for (int i = 0; i < sz; ++i)
        {
            for (int j = 0; j < sz; ++j)
            {
                int sum = prime[i] + prime[j];
                if (K > sum && !sieve[K - sum])
                {
                    flag = true;
                    cout << prime[i] << ' ' << prime[j] << ' ' << K - sum << '\n';
                    break;
                }
            }
            if (flag)
                break;
        }
        if (!flag)
            cout << 0 << '\n';
    }

    return 0;
}