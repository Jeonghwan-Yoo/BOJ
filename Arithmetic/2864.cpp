#include <iostream>

using namespace std;

int Convert(int num, int from, int to)
{
    int val = 0;
    int exp = 1;
    while (num)
    {
        int cur = num % 10;
        if (cur == from)
            cur = to;
        val += cur * exp;
        exp *= 10;
        num /= 10;
    }

    return val;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B;
    cin >> A >> B;
    cout << Convert(A, 6, 5) + Convert(B, 6, 5) << ' ' << Convert(A, 5, 6) + Convert(B, 5, 6);

    return 0;
}