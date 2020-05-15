#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int price[10'001] = { 0, };
    int maxVal = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> price[i];
        maxVal = max(maxVal, price[i]);
    }

    int M;
    cin >> M;

    int l = 0;
    int r = maxVal;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            if (price[i] <= mid)
                sum += price[i];
            else
                sum += mid;
        }
        if (sum <= M)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r;
    
    return 0;
}