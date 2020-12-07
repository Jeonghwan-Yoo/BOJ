#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int eye1, eye2, eye3;
    cin >> eye1 >> eye2 >> eye3;
    if (eye1 == eye2 && eye2 == eye3)
        cout << 10'000 + eye1 * 1'000;
    else if (eye1 == eye2 || eye1 == eye3)
        cout << 1'000 + eye1 * 100;
    else if (eye2 == eye3)
        cout << 1'000 + eye2 * 100;
    else
        cout << max({ eye1, eye2, eye3 }) * 100;

    return 0;
}