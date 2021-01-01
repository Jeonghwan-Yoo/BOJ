#include <iostream>

using namespace std;

#define MAX_N 1'000'000

bool sieve[MAX_N + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve[0] = sieve[1] = true;
    for (int i = 2; i * i <= MAX_N; ++i)
        if (!sieve[i])
            for (int j = i * i; j <= MAX_N; j += i)
                sieve[j] = true;

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int cnt = 0;
        for (int i = 2; i <= (N >> 1); ++i)
            if (!sieve[i] && !sieve[N - i])
                ++cnt;
        cout << cnt << '\n';
    }

    return 0;
}