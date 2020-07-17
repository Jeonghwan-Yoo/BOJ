#include <iostream>

using namespace std;

int N, M, K;
long long arr[1'000'001];
long long tree[1'000'001 << 2];
long long lazy[1'000'001 << 2];

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

void Push(int k, int tl, int tr)
{
    if (lazy[k] == 0ll)
        return;
    tree[k] += (tr - tl + 1) * lazy[k];
    if (tl != tr)
    {
        lazy[k << 1] += lazy[k];
        lazy[k << 1 | 1] += lazy[k];
    }
    lazy[k] = 0ll;
}

void Update(int k, int pl, int pr, long long diff, int tl, int tr)
{
    Push(k, tl, tr);
    if (pr < tl || tr < pl)
        return;
    if (pl <= tl && tr <= pr)
    {
        tree[k] += (tr - tl + 1) * diff;
        if (tl != tr)
        {
            lazy[k << 1] += diff;
            lazy[k << 1 | 1] += diff;
        }
        return;
    }

    int mid = (tl + tr) >> 1;
    Update(k << 1, pl, pr, diff, tl, mid);
    Update(k << 1 | 1, pl, pr, diff, mid + 1, tr);

    tree[k] = tree[k << 1] + tree[k << 1 | 1];
}

long long Query(int k, int ql, int qr, int tl, int tr)
{
    Push(k, tl, tr);
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
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            long long d;
            cin >> d;
            Update(1, b, c, d, 1, N);
        }
        else if (a == 2)
            cout << Query(1, b, c, 1, N) << '\n';
    }

    return 0;
}