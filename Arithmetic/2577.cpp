#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C;
    cin >> A >> B >> C;
    int mul = A * B * C;
    int cnt[10] = { 0, };
    while (mul)
    {
        ++cnt[mul % 10];
        mul /= 10;
    }
    for (int i = 0; i <= 9; ++i)
        cout << cnt[i] << '\n';

    return 0;
}