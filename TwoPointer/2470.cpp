#include <iostream>
#include <algorithm>

using namespace std;

#define INF 2e9

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int arr[100001] = { 0, };
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr, arr + N);
    int l = 0;
    int r = N - 1;
    int minSum = INF;
    int lVal = 0;
    int rVal = 0;
    while (l < r)
    {
        int sum = arr[l] + arr[r];
        int absSum = abs(sum);
        if (absSum < minSum)
        {
            minSum = absSum;
            lVal = arr[l];
            rVal = arr[r];
        }
        if (sum < 0)
            ++l;
        else
            --r;
    }
    cout << lVal << ' ' << rVal;
        
    return 0;
}