#include <iostream>

using namespace std;

bool sieve[1'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;
    for (int i = 2; i * i <= N; ++i)
        if (!sieve[i])
            for (int j = i * i; j <= N; j += i)
                sieve[j] = true;
    sieve[1] = true;

    for (int i = M; i <= N; ++i)
        if (!sieve[i])
            cout << i << '\n';

    return 0;
}