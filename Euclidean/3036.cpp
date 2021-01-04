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

    int N;
    cin >> N;
    int dividend;
    cin >> dividend;
    for (int i = 1; i < N; ++i)
    {
        int divisor;
        cin >> divisor;
        int gcd = 0;
        if (divisor > dividend)
            gcd = Gcd(divisor, dividend);
        else
            gcd = Gcd(dividend, divisor);
        cout << dividend / gcd << '/' << divisor / gcd << '\n';
    }

    return 0;
}