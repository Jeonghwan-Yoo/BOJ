#include <iostream>

using namespace std;

int cnt[10'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int in;
    for (int i = 0; i < N; ++i)
    {
        cin >> in;
        ++cnt[in];
    }
    int idx = 0;
    for (int i = 0; i <= 10'000; ++i)
        for (int j = 0; j < cnt[i]; ++j)
            cout << i << '\n';

    return 0;
}