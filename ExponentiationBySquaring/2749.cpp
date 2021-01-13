#include <iostream>

using namespace std;

struct Matrix
{
    long long a00, a01, a10, a11;
    int p;
    Matrix operator*(const Matrix &b) const
    {
        return { (a00 * b.a00 + a01 * b.a10) % p, (a00 * b.a01 + a01 * b.a11) % p, 
                 (a10 * b.a00 + a11 * b.a10) % p, (a10 * b.a01 + a11 * b.a11) % p, p };
    }
};

Matrix ModPow2(Matrix a, long long n)
{
    if (n == 0)
        return { 1ll, 0ll, 0ll, 1ll, a.p };
    
    if (n & 1)
        return a * ModPow2(a, n - 1);
    return ModPow2(a * a, n >> 1);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    Matrix mat{ 1ll, 1ll, 1ll, 0ll, (int)1e6 };
    cout << ModPow2(mat, n).a01;

    return 0;
}