#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > line;
vector<int> dp;
int sz[100'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        line.emplace_back(a, b);
    }
    sort(line.begin(), line.end());

    dp.emplace_back(line[0].second);
    int cnt = 0;
    sz[0] = cnt;
    for (int i = 1; i < N; ++i)
    {
        if (dp.back() < line[i].second)
        {
            dp.emplace_back(line[i].second);
            ++cnt;
            sz[i] = cnt;
        }
        else
        {
            auto lb = lower_bound(dp.begin(), dp.end(), line[i].second);
            *lb = line[i].second;
            sz[i] = lb - dp.begin();
        }
    }

    vector<int> lis;
    for (int i = N - 1; i >= 0; --i)
    {
        if (cnt == sz[i])
            --cnt;
        else
            lis.emplace_back(line[i].first);
    }
    cout << (int)lis.size() << '\n';
    for (int i = (int)lis.size() - 1; i >= 0; --i)
        cout << lis[i] << '\n';

    return 0;
}