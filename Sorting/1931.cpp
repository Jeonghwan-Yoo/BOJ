#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> time[100'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> time[i].second >> time[i].first;
    
    sort(time, time + N);
    int now = time[0].first;
    int cnt = 1;
    for (int i = 1; i < N; ++i)
    {
        if (time[i].second >= now)
        {
            ++cnt;
            now = time[i].first;
        }
    }
    cout << cnt;

    return 0;
}