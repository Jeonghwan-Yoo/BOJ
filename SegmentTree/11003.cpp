#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9

int tree[5'000'000 << 1];
int N, L;

void Update(int k, int x)
{
    k += N;
    tree[k] = x;
    for (k >>= 1; k >= 1; k >>= 1)
        tree[k] = min(tree[k << 1], tree[(k << 1) + 1]);
}

int Query(int a, int b)
{
    a += N;
    b += N;
    int val = INF;
    while (a <= b)
    {
        if ((a & 1) == 1)
        {
            val = min(val, tree[a]);
            ++a;
        }
        if ((b & 1) == 0)
        {
            val = min(val, tree[b]);
            --b;
        }
        a >>= 1;
        b >>= 1;
    }
    return val;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L;
    for (int i = 1; i <= N; ++i)
    {
        int in;
        cin >> in;
        Update(i, in);
    }
    int a = 1;
    int b = 1;
    while (b <= N)
    {
        while ((b - a) < L)
        {
            cout << Query(a, b) << ' ';
            ++b;
        }
        ++a;
    }
    return 0;
}