#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> dp;
    int in;
    cin >> in;
    dp.emplace_back(in);
    for (int i = 1; i < n; ++i)
    {
        cin >> in;
        if (dp.back() < in)
            dp.emplace_back(in);
        else
        {
            int l = 0;
            int r = (int)dp.size() - 1;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (dp[mid] >= in)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            dp[r + 1] = in;
        }
    }
    cout << (int)dp.size();

    return 0;
}