#include <iostream>
#include <string>

using namespace std;

int fail[1'000'001];
char roulette[1'000'001];

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> roulette[i];
    for (int i = 0; i < N; ++i)
        cin >> roulette[i];
    
    for (int i = 1, j = 0; i < N; ++i)
    {
        while (j > 0 && roulette[i] != roulette[j])
            j = fail[j - 1];
        if (roulette[i] == roulette[j])
        {
            ++j;
            fail[i] = j;
        }
    }
    int minSz = N - fail[N - 1];
    int dividend = 0;
    if (N % minSz == 0)
        dividend = N / minSz;
    else
        dividend = 1;
    
    int gcd = Gcd(N, dividend);
    cout << dividend / gcd << '/' << N / gcd;

    return 0;
}