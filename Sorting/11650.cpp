#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> xy[100'001];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> xy[i].first >> xy[i].second;
    
    sort(xy, xy + N);
    for (int i = 0; i < N; ++i)
        cout << xy[i].first << ' ' << xy[i].second << '\n';

    return 0;
}