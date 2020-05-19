#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum Fav
{
    Start = 301,
    End = 1130,
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<pair<int, int> > flowers;
    for (int i = 0; i < N; ++i)
    {
        int mFrom, dFrom, mTo, dTo;
        cin >> mFrom >> dFrom >> mTo >> dTo;
        flowers.emplace_back(mFrom * 100 + dFrom, mTo * 100 + dTo);
    }
    sort(flowers.begin(), flowers.end());
    int target = Fav::Start;
    int cnt = 0;
    for (int i = 0; i < (int)flowers.size(); ++i)
    {
        bool link = false;
        int to = target;
        while (i < (int)flowers.size())
        {
            if (flowers[i].first > target)
                break;
            if (to < flowers[i].second)
            {
                to = flowers[i].second;
                link = true;
            }
            ++i;
        }
        --i;
        if (link == true)
        {
            target = to;
            ++cnt;
            if (to > Fav::End)
                break;
        }
        else
            break;
    }
    if (target <= Fav::End)
        cnt = 0;
    cout << cnt;
    
    return 0;
}