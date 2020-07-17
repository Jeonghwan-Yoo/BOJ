#include <iostream>

using namespace std;

int tree[100'001 << 2];
bool lazy[100'001 << 2];

void Push(int k, int tl, int tr)
{
    if (lazy[k] == false)
        return;

    tree[k] = (tr - tl + 1) - tree[k];
    if (tl != tr)
    {
        lazy[k << 1] ^= 1;
        lazy[k << 1 | 1] ^= 1;
    }
    lazy[k] = false;
}

void Update(int k, int pl, int pr, int tl, int tr)
{
    Push(k, tl, tr);
    if (pr < tl || tr < pl)
        return;
    
    if (pl <= tl && tr <= pr)
    {
        tree[k] = (tr - tl + 1) - tree[k];
        if (tl != tr)
        {
            lazy[k << 1] ^= 1;
            lazy[k << 1 | 1] ^= 1;
        }
        return;
    }

    int mid = (tl + tr) >> 1;
    Update(k << 1, pl, pr, tl, mid);
    Update(k << 1 | 1, pl, pr, mid + 1, tr);

    tree[k] = tree[k << 1] + tree[k << 1 | 1];
}

int Query(int k, int ql, int qr, int tl, int tr)
{
    Push(k, tl, tr);
    if (qr < tl || tr < ql)
        return 0;

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

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int O, S, T;
        cin >> O >> S >> T;
        if (O == 0)
            Update(1, S, T, 1, N);
        else
            cout << Query(1, S, T, 1, N) << '\n';
    }
    return 0;
}