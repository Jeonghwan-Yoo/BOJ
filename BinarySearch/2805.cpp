#include <iostream>

using namespace std;

int tree[1'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> tree[i];
    int l = 0;
    int r = 2e9;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        long long leftover = 0;
        for (int i = 0; i < N; ++i)
        {
            if (tree[i] - mid > 0)
                leftover += tree[i] - mid;
            if (leftover >= M)
                break;
        }
        if (leftover >= M)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r;
    return 0;
}