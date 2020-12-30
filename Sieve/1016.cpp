#include <iostream>
#include <cmath>

using namespace std;

bool sieve[1'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long mn, mx;
    cin >> mn >> mx;
    
    int sz = mx - mn + 1;
    for (long long i = 2; i * i <= mx; ++i)
    {
        long long st = (long long)ceil((double)mn / (i * i));
        for (long long j = st; i * i * j <= mx; ++j)
            sieve[i * i * j - mn] = true;
    }

    int cnt = 0;
    for (int i = 0; i < sz; ++i)
        if (!sieve[i])
            ++cnt;
    cout << cnt;

    return 0;
}