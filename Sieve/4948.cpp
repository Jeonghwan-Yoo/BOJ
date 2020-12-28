#include <iostream>

using namespace std;

#define MAX_N 123'456 << 1

bool sieve[MAX_N + 1];
int psum[MAX_N + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve[1] = true;
    for (int i = 2; i * i <= MAX_N; ++i)
        if (!sieve[i])
            for (int j = i * i; j <= MAX_N; j += i)
                sieve[j] = true;

    psum[2] = 1;
    for (int i = 3; i <= MAX_N; ++i)
        psum[i] = psum[i - 1] + !sieve[i];

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        
        cout << psum[n << 1] - psum[n] << '\n';
    }

    return 0;
}