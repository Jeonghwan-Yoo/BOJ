#include <iostream>
#include <vector>

using namespace std;

bool sieve[4'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> prime;
    sieve[1] = true;
    for (int i = 2; i <= N; ++i)
    {
        if (!sieve[i])
        {
            prime.emplace_back(i);
            for (long long j = (long long)i * i; j <= N; j += i)
                sieve[j] = true;
        }
    }

    int sz = (int)prime.size();
    int l = 0;
    int r = 0;
    int sum = 0;
    int cnt = 0;
    while (l < sz)
    {
        while (r < sz && sum < N)
        {
            sum += prime[r];
            ++r;
        }
        if (sum == N)
            ++cnt;
        sum -= prime[l];
        ++l;
    }
    cout << cnt;

    return 0;
}