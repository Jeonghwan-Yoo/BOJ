#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int, int> yx[100'001];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> yx[i].second >> yx[i].first;
    
    sort(yx, yx + N);
    for (int i = 0; i < N; ++i)
        cout << yx[i].second << ' ' << yx[i].first << '\n';

    return 0;
}