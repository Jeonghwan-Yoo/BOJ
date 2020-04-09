#include <iostream>
#include <cstring>

using namespace std;

int cache[41];
int cntOne[41];
int cntZero[41];

int fibo(int n)
{
    if (n == 0)
    {
        cntZero[0] = 1;
        cache[0] = 0;
        return 0;
    }
    else if (n == 1)
    {
        cntOne[1] = 1;
        cache[1] = 1;
        return 1;
    }
    if (cache[n] != -1)
    {
        return cache[n];
    }
    cache[n] = fibo(n - 1) + fibo(n - 2);
    cntOne[n] = cntOne[n - 1] + cntOne[n - 2];
    cntZero[n] = cntZero[n - 1] + cntZero[n - 2];
    return cache[n];
}


int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    memset(cache, -1, sizeof(cache));
    fibo(40);
    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;
        cout << cntZero[n] << ' ' << cntOne[n] << '\n';
    }
    return 0;
}