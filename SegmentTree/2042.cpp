#include <iostream>

using namespace std;

int N, M, K;
long long arr[1'000'001];
long long tree[1'000'001 << 1];

void Build(int k, int tl, int tr)
{
    if (tl == tr)
    {
        tree[k] = arr[tl];
        return;
    }
    int mid = (tl + tr) >> 1;
    Build(k << 1, tl, mid);
    Build(k << 1 | 1, mid + 1, tr);

    tree[k] = tree[k << 1] + tree[k << 1 | 1];
}

void Update(int k, int pos, long long x, int tl, int tr)
{
    if (pos < tl || tr < pos)
        return;
    if (tl == tr)
    {
        tree[k] = x;
        return;
    }
    int mid = (tl + tr) >> 1;
    Update(k << 1, pos, x, tl, mid);
    Update(k << 1 | 1, pos, x, mid + 1, tr);

    tree[k] = tree[k << 1] + tree[k << 1 | 1];
}

long long Query(int k, int ql, int qr, int tl, int tr)
{
    if (qr < tl || ql > tr)
        return 0ll;
    if (ql <= tl && tr <= qr)
        return tree[k];

    int mid = (tl + tr) >> 1;
    return Query(k << 1, ql, qr, tl, mid) + Query(k << 1 | 1, ql, qr, mid + 1, tr);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];

    Build(1, 1, N);
    for (int i = 0; i < M + K; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            long long c;
            cin >> c;
            Update(1, b, c, 1, N);
        }
        else if (a == 2)
        {
            int c;
            cin >> c;
            cout << Query(1, b, c, 1, N) << '\n';
        }
    }

    return 0;
}