#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A + B) % C << '\n';
    cout << ((A % C) + (B % C)) % C << '\n';
    cout << (A * B) % C << '\n';
    cout << ((A % C) * (B % C)) % C << '\n';

    return 0;
}