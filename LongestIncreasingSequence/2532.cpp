#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > animal;
vector<int> dp;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int n, l, r;
    for (int i = 0; i < N; ++i)
    {
        cin >> n >> l >> r;
        animal.emplace_back(l, -r);
    }

    sort(animal.begin(), animal.end());

    dp.emplace_back(animal[0].second);
    int cnt = 0;
    for (int i = 1; i < N; ++i)
    {
        if (animal[i - 1].first == animal[i].first && animal[i - 1].second == animal[i].second)
            continue;
        if (dp.back() <= animal[i].second)
        {
            dp.emplace_back(animal[i].second);
            ++cnt;
        }
        else
        {
            auto lb = upper_bound(dp.begin(), dp.end(), animal[i].second);
            *lb = animal[i].second;
        }
    }
    cout << cnt + 1;

    return 0;
}