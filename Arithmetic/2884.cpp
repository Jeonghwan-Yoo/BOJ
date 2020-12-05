#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, M;
    cin >> H >> M;
    cout << (H + 23 + (M + 15) / 60) % 24 << ' ' << (M + 15) % 60;

    return 0;
}