#include <iostream>
#include <algorithm>

using namespace std;

long long tree[100'001 << 1];
int N, Q;

void Build(int n)
{
    while (n >= 1)
    {
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
        --n;
    }
}

void Update(int k, int x)
{
    k += N;
    tree[k] = x;
    while (k >= 1)
    {
        k >>= 1;
        tree[k] = tree[k << 1] + tree[k << 1 | 1];
    }
}

long long Query(int l, int r)
{
    l += N;
    r += N;
    long long sum = 0ll;
    while (l <= r)
    {
        if ((l & 1) == 1)
        {
            sum += tree[l];
            ++l;
        }
        if ((r & 1) == 0)
        {
            sum += tree[r];
            --r;
        }
        l >>= 1;
        r >>= 1;
    }
    return sum;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    for (int i = N + 1; i <= (N << 1); ++i)
        cin >> tree[i];
    Build(N);
    int x, y, a, b;
    for (int i = 0; i < Q; ++i)
    {
        cin >> x >> y >> a >> b;
        if (x > y)
            swap(x, y);
        cout << Query(x, y) << '\n';
        Update(a, b);
    }

    return 0;
}