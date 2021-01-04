#include <iostream>
#include <algorithm>

using namespace std;

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int Lcm(int a, int b)
{
    return a * b / Gcd(a, b);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    if (A < B)
        swap(A, B);
    cout << Gcd(A, B) << '\n' << Lcm(A, B);

    return 0;
}