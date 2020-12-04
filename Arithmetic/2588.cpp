#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B;
    cin >> A >> B;
    cout << A * (B % 10) << '\n';
    cout << A * (B / 10 % 10) << '\n';
    cout << A * (B / 100) << '\n';
    cout << A * B;

    return 0;
}