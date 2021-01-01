#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 1'299'709

bool sieve[MAX_N + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i * i <= MAX_N; ++i)
        if (!sieve[i])
            for (int j = i * i; j <= MAX_N; j += i)
                sieve[j] = true;

    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;
        int l = K;
        int r = K;
        while (l > 1)
        {
            if (!sieve[l])
                break;
            --l;
        }
        while (r <= MAX_N)
        {
            if (!sieve[r])
                break;
            ++r;
        }
        cout << r - l << '\n';
    }

    return 0;
}