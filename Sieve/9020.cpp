#include <iostream>

using namespace std;

#define MAX_N 10'000

bool sieve[MAX_N + 1];

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

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        
        int n2 = n >> 1;
        for (int i = n2; i >= 2; --i)
        {
            if (!sieve[i] && !sieve[n - i])
            {
                cout << i << ' ' << n - i << '\n';
                break;
            }
        }
    }

    return 0;
}