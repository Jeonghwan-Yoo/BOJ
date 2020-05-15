#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int K, N;
    cin >> K >> N;
    int arr[10'001] = { 0, };
    for (int i = 0; i < K; ++i)
        cin >> arr[i];
    long long l = 0;
    long long r = (1 << 31) - 1;
    while (l <= r)
    {
        long long mid = (l + r) >> 1;
        long long num = 0;
        for (int i = 0; i < K; ++i)
        {
            num += arr[i] / mid;
            if (num >= N)
                break;
        }
        if (num >= N)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r;
    return 0;
}