#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int Dist(const pair<int, int> &a, const pair<int, int> &b)
{
    int diffX = a.second - b.second;
    int diffY = a.first - b.first;
    return diffX * diffX + diffY * diffY;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    pair<int, int> yx[100'001];
    for (int i = 0; i < N; ++i)
        cin >> yx[i].second >> yx[i].first;
    sort(yx, yx + N, [&yx](const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second < b.second;
    });
    set<pair<int, int> > points = { yx[0], yx[1] };
    int minDist = Dist(yx[0], yx[1]);
    int start = 0;
    for (int i = 2; i < N; ++i)
    {
        pair<int, int> cur = yx[i];
        while (start < i)
        {
            pair<int, int> prev = yx[start];
            int diffX = cur.second - prev.second;
            if (diffX * diffX > minDist)
            {
                points.erase(prev);
                ++start;
            }
            else
                break;
        }
        int dist = (int)sqrt((double)minDist);
        auto lower = points.lower_bound({ cur.first - dist, -100'000 });
        auto upper = points.upper_bound({ cur.first + dist, 100'000 });
        for (auto it = lower; it != upper; ++it)
        {
            int d = Dist(cur, *it);
            if (minDist > d)
                minDist = d;
        }
        points.insert(cur);
    }
    cout << minDist;
    
    return 0;
}