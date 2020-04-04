#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    int res = 0;
    if (N > 5)
    {
        int tmp = N;
        int sum = 0;
        while (tmp)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum & 1)
            res = 1;
    }
    int prime[2700] = { 0, };
    prime[0] = -1;
    prime[1] = -1;
    for (int i = 2; i < 2700; ++i)
    {
        if (prime[i] == -1)
            continue;
        for (int j = 2; i * j < 2700; ++j)
        {
            prime[i * j] = -1;
        }
    }
    for (int i = 2; i < 2700; ++i)
    {
        if (i <= N && prime[i] == 0)
        {
            if (N % i == 0)
            {
                prime[i] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 2; i < 2700; ++i)
    {
        if (prime[i] == 1)
        {
            ++sum;
        }
    }
    if (N == 4 || N == 2 || (sum != 0 && (sum & 1) == 0))
    {
        res = 2 * res + 2;
    }
    if (res == 0)
    {
        res = 3;
    }
    cout << res;
    return 0;
}