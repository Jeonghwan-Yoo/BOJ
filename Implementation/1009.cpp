#include <iostream>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    int a, b;
    for (int i = 0; i < T; ++i) {
        cin >> a >> b; 
        b &= 3;
        if (b == 0)
            b = 4;

        int res = 1;
        for (int j = 0; j < b; ++j) {
            res *= a;
            res %= 10;
        }
        if (res == 0)
            res = 10;
        cout << res << '\n';
    }
    return 0;
}