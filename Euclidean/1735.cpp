#include <iostream>

using namespace std;

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

    int A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;
    int divisor = A2 * B2;
    int dividend = divisor / A2 * A1 + divisor / B2 * B1;
    int gcd = 0;
    if (divisor > dividend)
        gcd = Gcd(divisor, dividend);
    else
        gcd = Gcd(dividend, divisor);
    cout << dividend / gcd << ' ' << divisor / gcd;

    return 0;
}