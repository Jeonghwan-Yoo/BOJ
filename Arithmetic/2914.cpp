#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, I;
    cin >> A >> I;
    cout << A * (I - 1) + 1;

    return 0;
}