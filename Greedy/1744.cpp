#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int arr[10'001] = { 0, };
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    sort(arr, arr + N);
    int l = 0;
    int sum = 0;
    while (l < N - 1)
    {
        if (arr[l + 1] > 0)
            break;
        sum += arr[l] * arr[l + 1];
        l += 2;
    }
    int r = N - 1;
    while (r > 0)
    {
        if (arr[r - 1] <= 1)
            break;
        sum += arr[r] * arr[r - 1];
        r -= 2;
    }
    for (int i = l; i <= r; ++i)
        sum += arr[i];

    cout << sum;

    return 0;
}