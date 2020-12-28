#include <iostream>

using namespace std;

#define MAX_N 1'000'000

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

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        
        bool flag = false;
        int n2 = n >> 1;
        for (int i = 3; i <= n2; ++i)
        {
            if (!sieve[i] && !sieve[n - i])
            {
                flag = true;
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
        if (!flag)
            cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}