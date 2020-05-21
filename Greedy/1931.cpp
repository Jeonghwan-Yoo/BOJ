#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> time[100'001];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> time[i].first >> time[i].second;

    sort(time, time + N, [&time](const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });
    int meeting = 0;
    int end = -1;
    for (int i = 0; i < N; ++i)
    {
        if (time[i].first >= end)
        {
            ++meeting;
            end = time[i].second;
        }
    }
    cout << meeting;
    
    
    return 0;
}