#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B;
    cin >> A >> B;
    cout << fixed << setprecision(9) << (double)A / B;

    return 0;
}