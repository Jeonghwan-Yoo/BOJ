#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9

int arr[100'001];
pair<int, int> tree[100'001 << 1];
int N, M;

void update(int k, int x)
{
    k += N;
    tree[k] = { x, x };
    for (k >>= 1; k >= 1; k >>= 1)
    {
        tree[k].first = min(tree[(k << 1)].first, tree[(k << 1) + 1].first);
        tree[k].second = max(tree[(k << 1)].second, tree[(k << 1) + 1].second);
    }
}

pair<int, int> minMax(int a, int b)
{
    a += N;
    b += N;
    pair<int, int> mm = { INF, 0 };
    while (a <= b)
    {
        if ((a & 1) == 1)
        {
            mm.first = min(mm.first, tree[a].first);
            mm.second = max(mm.second, tree[a].second);
            ++a;
        }
        if ((b & 1) == 0)
        {
            mm.first = min(mm.first, tree[b].first);
            mm.second = max(mm.second, tree[b].second);
            --b;
        }
        a >>= 1;
        b >>= 1;
    }
    return mm;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        tree[i].first = INF;
        tree[i].second = 0;
    }
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> mm = minMax(a, b);
        cout << mm.first << ' ' << mm.second << '\n';
    }

    return 0;
}