#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int conv[10'001];
vector<pair<int, int> > line;
vector<int> dp;
int sz[10'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int in;
    for (int i = 1; i <= N; ++i)
    {
        cin >> in;
        conv[in] = i;
    }
    for (int i = 1; i <= N; ++i)
    {
        cin >> in;
        line.emplace_back(conv[in], in);
    }

    dp.emplace_back(line[0].first);
    int cnt = 0;
    sz[0] = cnt;
    for (int i = 1; i < N; ++i)
    {
        if (dp.back() < line[i].first)
        {
            dp.emplace_back(line[i].first);
            ++cnt;
            sz[i] = cnt;
        }
        else
        {
            auto lb = lower_bound(dp.begin(), dp.end(), line[i].first);
            *lb = line[i].first;
            sz[i] = lb - dp.begin();
        }
    }

    vector<int> lis;
    cout << cnt + 1 << '\n';
    for (int i = N - 1; i >= 0; --i)
    {
        if (cnt == sz[i])
        {
            lis.emplace_back(line[i].second);
            --cnt;
        }
    }
    sort(lis.begin(), lis.end());
    for (int i = 0; i < (int)lis.size(); ++i)
        cout << lis[i] << ' ';
        
    return 0;
}