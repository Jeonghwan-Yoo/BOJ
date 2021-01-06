#include <iostream>

using namespace std;

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int seat[2'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D1, D2;
    cin >> D1 >> D2;

    for (int i = 1; i <= D2; ++i)
        seat[i] = i;

    for (int i = 1; i <= D2; ++i)
        for (int j = i << 1; j <= D2; j += i)
            seat[j] -= seat[i];

    for (int i = 1; i < D1; ++i)
    {
        for (int j = i << 1; j <= D2; j += i)
        {
            if (D1 <= j)
            {
                seat[j] += seat[i];
                break;
            }
        }
    }

    int cnt = 0;
    for (int i = D1; i <= D2; ++i)
        cnt += seat[i];
    cout << cnt;

    return 0;
}