#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100'001];
vector<int> tree[100'001 << 2];

void Build(int n, int tl, int tr)
{
    if (tl == tr)
    {
        tree[n].emplace_back(arr[tl]);
        return;
    }

    int mid = (tl + tr) >> 1;
    Build(n << 1, tl, mid);
    Build(n << 1 | 1, mid + 1, tr);

    merge(tree[n << 1].begin(), tree[n << 1].end(), tree[n << 1 | 1].begin(), tree[n << 1 | 1].end(), back_inserter(tree[n]));
}

int Query(int k, int ql, int qr, int x, int tl, int tr)
{
    if (qr < tl || tr < ql)
        return 0;
    
    if (ql <= tl && tr <= qr)
        return upper_bound(tree[k].begin(), tree[k].end(), x) - tree[k].begin();
    
    int mid = (tl + tr) >> 1;
    return Query(k << 1, ql, qr, x, tl, mid) + Query(k << 1 | 1, ql, qr, x, mid + 1, tr);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];

    Build(1, 1, N);

    int i, j, k;
    for (int m = 0; m < M; ++m)
    {
        cin >> i >> j >> k;
        int l = (int)-1e9;
        int r = (int)1e9;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int num = Query(1, i, j, mid, 1, N);
            if (num >= k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout << l << '\n';
    }

    return 0;
}