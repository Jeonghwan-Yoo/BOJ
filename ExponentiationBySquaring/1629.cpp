#include <iostream>

using namespace std;

int ModPow(long long a, int n, int p)
{
    if (n == 0)
        return 1;
    
    if (n & 1)
        return a * ModPow(a, n - 1, p) % p;
    return ModPow(a * a % p, n >> 1, p);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;
    cout << ModPow(A, B, C);

    return 0;
}