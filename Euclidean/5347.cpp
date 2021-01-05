#include <iostream>

using namespace std;

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

long long Lcm(int a, int b)
{
    return (long long)a / Gcd(a, b) * b;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << Lcm(a, b) << '\n';
    }
    
    return 0;
}