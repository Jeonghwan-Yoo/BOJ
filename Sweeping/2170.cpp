#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int> > line;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    line.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> line[i].first >> line[i].second;
    sort(line.begin(), line.end());
    int from = line[0].first;
    int to = line[0].second;
    int dist = 0;
    for (int i = 1; i < line.size(); ++i)
    {
        if (to < line[i].first)
        {
            dist += to - from;
            from = line[i].first;
            to = line[i].second;
        }
        if (to < line[i].second)
            to = line[i].second;
    }
    dist += to - from;
    cout << dist;

    return 0;
}