#include <iostream>

using namespace std;

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

long long Lcm(long long a, long long b)
{
    return a / Gcd(a, b) * b;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    if (A > B)
        cout << Lcm(A, B);
    else
        cout << Lcm(B, A);

    return 0;
}