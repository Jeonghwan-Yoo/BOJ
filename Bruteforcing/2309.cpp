#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum = 0;
    int arr[9];
    for (int i = 0; i < 9; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + 9);
    bool flag = false;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = i + 1; j < 9; ++j)
        {
            if (sum - arr[i] - arr[j] == 100)
            {
                flag = true;
                for (int k = 0; k < 9; ++k)
                    if (k != i && k != j)
                        cout << arr[k] << '\n';
            }
        }
        if (flag)
            break;
    }

    return 0;
}