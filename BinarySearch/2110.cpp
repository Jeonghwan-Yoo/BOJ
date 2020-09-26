#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, C;
    cin >> N >> C;
    vector<int> x(N);
    for (int i = 0; i < N; ++i)
        cin >> x[i];
    sort(x.begin(), x.end());
    
    int l = 0;
    int r = x[N - 1] - x[0];
    int maxDiff = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int cnt = 1;
        int st = x[0];
        for (int i = 1; i < N; ++i)
        {
            if (x[i] - st >= mid)
            {
                ++cnt;
                st = x[i];
            }
        }

        if (cnt >= C)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1;
    
    return 0;
}