#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1e9

int Dist(const pair<int, int> &a, const pair<int, int> &b)
{
    int diffX = a.second - b.second;
    int diffY = a.first - b.first;
    return diffX * diffX + diffY * diffY;
}

int BruteForcing(const pair<int, int> (&yx)[100'001], int left, int right)
{
    int minDist = INF;
    for (int i = left; i < right; ++i)
        for (int j = i + 1; j <= right; ++j)
            minDist = min(minDist, Dist(yx[i], yx[j]));
    return minDist;
}

int ClosestDist(const pair<int, int> (&yx)[100'001], int left, int right)
{
    if (right - left <= 2)
        return BruteForcing(yx, left, right);
    int mid = (left + right) >> 1;
    int minDist = min(ClosestDist(yx, left, mid - 1), ClosestDist(yx, mid + 1, right));

    vector<pair<int, int> > points;
    points.emplace_back(yx[mid]);
    int midX = yx[mid].second;

    for (int i = mid - 1; i >= left; --i)
    {
        if ((midX - yx[i].second) * (midX - yx[i].second) >= minDist)
            break;
        points.emplace_back(yx[i]);
    }
    for (int i = mid + 1; i <= right; ++i)
    {
        if ((yx[i].second - midX) * (yx[i].second - midX) >= minDist)
            break;
        points.emplace_back(yx[i]);
    }
    sort(points.begin(), points.end());
    for (int i = 0; i < (int)points.size() - 1; ++i)
    {
        for (int j = i + 1; j < (int)points.size(); ++j)
        {
            if ((points[i].first - points[j].first) * (points[i].first - points[j].first) >= minDist)
                break;
            minDist = min(minDist, Dist(points[i], points[j]));
        }
    }
    return minDist;
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
    cout << ClosestDist(yx, 0, N - 1);
    
    return 0;
}