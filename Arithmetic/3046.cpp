#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int R1, S;
    cin >> R1 >> S;
    cout << (S << 1) - R1;   

    return 0;
}