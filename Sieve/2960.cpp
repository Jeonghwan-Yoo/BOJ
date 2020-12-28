#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> sieve(N + 1);
    int val = 0;
    sieve[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        for (int j = i; j <= N; j += i)
        {
            if (!sieve[j])
            {
                sieve[j] = 1;
                --K;
                if (K == 0)
                {
                    val = j;
                    break;
                }
            }
        }
        if (val)
            break;
    }
    cout << val;

    return 0;
}