#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1'000'000 << 1

bool sieve[MAX_N + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    sieve[1] = true;
    for (long long i = 2; i <= MAX_N; ++i)
    {
        if (!sieve[i])
        {
            if (i >= N)
            {
                int tmp = i;
                int rev = 0;
                while (tmp)
                {
                    rev = rev * 10 + tmp % 10;
                    tmp /= 10;
                }
                if (i == rev)
                {
                    cout << i;
                    break;
                }
            }
            for (long long j = i * i; j <= MAX_N; j += i)
                sieve[j] = true;
        }
    }

    return 0;
}