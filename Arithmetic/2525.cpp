#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C;
    cin >> A >> B >> C;
    int minute = B + C;
    cout << (A + minute / 60) % 24 << ' ' << minute % 60; 

    return 0;
}