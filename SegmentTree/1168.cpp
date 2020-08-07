#include <iostream>

using namespace std;

int N, K;
int tree[100'001 << 2];

void Build(int n, int tl, int tr)
{
    if (tl == tr)
    {
        tree[n] = 1;
        return;
    }

    int mid = (tl + tr) >> 1;
    Build(n << 1, tl, mid);
    Build(n << 1 | 1, mid + 1, tr);

    tree[n] = tree[n << 1] + tree[n << 1 | 1];
}

int Query(int k, int q, int tl, int tr)
{
    --tree[k];
    if (tl == tr)
        return tl;
    
    int mid = (tl + tr) >> 1;
    if (tree[k << 1] >= q)
        return Query(k << 1, q, tl, mid);
    return Query(k << 1 | 1, q - tree[k << 1], mid + 1, tr);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    
    Build(1, 1, N);

    cout << "<";
    int pos = 1;
    for (int i = N; i > 1; --i)
    {
        pos = (pos + K - 2) % i + 1;
        cout << Query(1, pos, 1, N) << ", ";
    }
    cout << Query(1, 1, 1, N) << ">";

    return 0;
}