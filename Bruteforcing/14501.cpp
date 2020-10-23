#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Dfs(int idx, int sum, vector<pair<int, int>> const &arr)
{
    if (idx > (int)arr.size())
        return 0;
    if (idx == (int)arr.size())
        return sum;

    int ret = 0;
    ret = max(ret, Dfs(idx + arr[idx].first, sum + arr[idx].second, arr));
    ret = max(ret, Dfs(idx + 1, sum, arr));

    return ret;
}

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
    
    cout << Dfs(0, 0, arr);

    return 0;
}