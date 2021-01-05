#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[2'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;
    vector<int> time(N);
    for (int i = 0; i < N; ++i)
        cin >> time[i];
    sort(time.begin(), time.end());

    for (int i = 0; i < N; ++i)
    {
        if (visited[time[i]])
            continue;

        for (int j = time[i]; j <= C; j += time[i])
            visited[j] = true;
    }

    int cnt = 0;
    for (int i = 0; i <= C; ++i)
        if (visited[i])
            ++cnt;
    cout << cnt;

    return 0;
}