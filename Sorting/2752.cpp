#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    if (num[0] > num[1])
        swap(num[0], num[1]);
    if (num[1] > num[2])
        swap(num[1], num[2]);
    if (num[0] > num[1])
        swap(num[0], num[1]);

    cout << num[0] << ' ' << num[1] << ' ' << num[2];

    return 0;
}