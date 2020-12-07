#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    C += D;
    B += C / 60;
    A += B / 60;
    A %= 24;
    B %= 60;
    C %= 60;
    cout << A << ' ' << B << ' ' << C;

    return 0;
}