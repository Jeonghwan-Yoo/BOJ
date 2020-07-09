#include <iostream>

using namespace std;

#define MOD (int)(1e9 + 7)

int N, M, K;
int tree[1'000'001 << 1];

void Build(int n)
{
    while (n >= 1)
    {
        tree[n] = ((long long)tree[n << 1] * tree[(n << 1) | 1]) % MOD;
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
        tree[k] = ((long long)tree[k << 1] * tree[(k << 1) | 1]) % MOD;
    }
}

int Query(int l, int r)
{
    l += N;
    r += N;
    int mul = 1;
    while (l <= r)
    {
        if ((l & 1) == 1)
        {
            mul = ((long long)mul * tree[l]) % MOD;
            ++l;
        }
        if ((r & 1) == 0)
        {
            mul = ((long long)mul * tree[r]) % MOD;
            --r;
        }
        l >>= 1;
        r >>= 1;
    }
    return (int)mul;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;

    for (int i = N + 1; i <= (N << 1); ++i)
        cin >> tree[i];

    Build(N);
        
    for (int i = 0; i < M + K; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            Update(b, c);
        else if (a == 2)
            cout << Query(b, c) << '\n';
    }
    return 0;
}