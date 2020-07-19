#include <iostream>

using namespace std;

int arr[500'001];
int tree[500'001 << 2];
int lazy[500'001 << 2];

void Build(int n, int tl, int tr)
{
    if (tl == tr)
    {
        tree[n] = arr[tl];
        return;
    }

    int mid = (tl + tr) >> 1;
    Build(n << 1, tl, mid);
    Build(n << 1 | 1, mid + 1, tr);
    
    tree[n] = tree[n << 1] ^ tree[n << 1 | 1];
}

void Push(int k, int tl, int tr)
{
    if (lazy[k] == 0)
        return;
    
    if ((tr - tl + 1) & 1 == 1)
        tree[k] ^= lazy[k];
    if (tl != tr)
    {
        lazy[k << 1] ^= lazy[k];
        lazy[k << 1 | 1] ^= lazy[k];
    }
    lazy[k] = 0;
}

void Update(int k, int pl, int pr, int x, int tl, int tr)
{
    Push(k, tl, tr);
    if (pr < tl || tr < pl)
        return;
    
    if (pl <= tl && tr <= pr)
    {
        if ((tr - tl + 1) & 1 == 1)
            tree[k] ^= x;
        if (tl != tr)
        {
            lazy[k << 1] ^= x;
            lazy[k << 1 | 1] ^= x;
        }
        return;
    }

    int mid = (tl + tr) >> 1;
    Update(k << 1, pl, pr, x, tl, mid);
    Update(k << 1 | 1, pl, pr, x, mid + 1, tr);

    tree[k] = tree[k << 1] ^ tree[k << 1 | 1];
}

int Query(int k, int ql, int qr, int tl, int tr)
{
    Push(k, tl, tr);
    if (qr < tl || tr < ql)
        return 0;

    if (ql <= tl && tr <= qr)
        return tree[k];
    
    int mid = (tl + tr) >> 1;
    return Query(k << 1, ql, qr, tl, mid) ^ Query(k << 1 | 1, ql, qr, mid + 1, tr);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];
    
    Build(1, 1, N);
    
    int M;
    cin >> M;
    int t, i, j, k;
    for (int m = 0; m < M; ++m)
    {
        cin >> t >> i >> j;
        ++i;
        ++j;
        if (t == 1)
        {
            cin >> k;
            Update(1, i, j, k, 1, N);
        }
        else
            cout << Query(1, i, j, 1, N) << '\n';
    }

    return 0;
}