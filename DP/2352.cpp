#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> dp;
    int N;
    cin >> N;
    int in;
    cin >> in;
    dp.push_back(in);
    for (int i = 2; i <= N; ++i)
    {
        cin >> in;
        if (dp.back() < in)
            dp.emplace_back(in);
        else
        {
            auto lb = lower_bound(dp.begin(), dp.end(), in);
            *lb = in;
        }
    }
    cout << dp.size();

    return 0;
}