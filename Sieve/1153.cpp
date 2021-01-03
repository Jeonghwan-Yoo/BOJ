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

    sieve[0] = sieve[1] = true;
    for (long long i = 2; i * i <= MAX_N; ++i)
        if (!sieve[i])
            for (long long j = i * i; j <= MAX_N; j += i)
                sieve[j] = true;

    int N;
    cin >> N;
    if (N < 2 + 2 + 2 + 2)
        cout << -1;
    else
    {
        vector<int> sum;
        sum.emplace_back(2);
        N -= 2;
        int odd = N & 1;
        sum.emplace_back(2 + odd);
        N -= 2 + odd;
        for (int i = 2; i <= (MAX_N >> 1); ++i)
        {
            if (!sieve[N - i])
            {
                sum.emplace_back(i);
                sum.emplace_back(N - i);
                break;
            }
        }

        for (int i = 0; i < 4; ++i)
            cout << sum[i] << ' ';
    }

    return 0;
}