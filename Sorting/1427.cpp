#include <iostream>
#include <algorithm>

using namespace std;

char arr[11];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i = 0;
    while (cin >> arr[i])
        ++i;

    sort(arr, arr + i);
    while (i > 0)
    {
        --i;
        cout << arr[i] - '0';
    }

    return 0;
}