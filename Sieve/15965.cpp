#include <iostream>

using namespace std;

#define MAX_N 8'000'000

bool sieve[MAX_N + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    sieve[0] = sieve[1] = true;
    for (long long i = 2; i <= MAX_N; ++i)
    {
        if (!sieve[i])
        {
            --K;
            if (K == 0)
            {
                cout << i;
                break;
            }
            for (long long j = i * i; j <= MAX_N; j += i)
                sieve[j] = true;
        }
    }

    return 0;
}