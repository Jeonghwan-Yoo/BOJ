#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    cout << L - max((A + C - 1) / C, (B + D - 1) / D);

    return 0;
}