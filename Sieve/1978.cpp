#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sieve(1'001);
    sieve[1] = 1;
    for (int i = 2; i <= 1'000; ++i)
    {
        if (sieve[i])
            continue;
        for (int j = i << 1; j <= 1'000; j += i)
            sieve[j] = 1;
    }

    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        if (!sieve[num])
            ++cnt;
    }
    cout << cnt;

    return 0;
}