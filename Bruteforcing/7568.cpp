#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i].first >> arr[i].second;
    
    vector<int> rank(N);
    for (int i = 0; i < N; ++i)
    {
        int cnt = 1;
        for (int j = 0; j < N; ++j)
            if (arr[i].first < arr[j].first && arr[i].second < arr[j].second)
                ++cnt;
        rank[i] = cnt;
    }
    for (int i = 0; i < N; ++i)
        cout << rank[i] << ' ';

    return 0;
}