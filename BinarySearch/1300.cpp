#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    int l = 1;
    int r = K;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int cnt = 0;
        int last = 0;
        for (int i = 1; i * i <= mid; ++i)
        {
            cnt += min(mid / i, N);
            last = i;
        }
        cnt += cnt - last * last;
        
        if (cnt >= K)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << r + 1;

    return 0;
}