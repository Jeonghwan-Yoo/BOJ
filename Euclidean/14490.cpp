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

    char delimiter;
    int a, b;
    cin >> a >> delimiter >> b;
    int gcd = Gcd(a, b);
    cout << a / gcd << ':' << b / gcd;
    
    return 0;
}