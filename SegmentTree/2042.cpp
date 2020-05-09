#include <iostream>

using namespace std;

int N, M, K;

long long arr[1'000'001];
long long tree[1'000'001];

long long sum(long long k)
{
    long long s = 0;
    while (k >= 1)
    {
        s += tree[k];
        k -= k & -k;
    }
    return s;
}

void update(long long k, long long x)
{
    while (k <= N)
    {
        tree[k] += x;
        k += k & -k;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        update(i, arr[i]);
    }
    for (int i = 0; i < M + K; ++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(b, -arr[b] + c);
            arr[b] = c;
        }
        else if (a == 2)
            cout << sum(c) - sum(b - 1) << '\n';
    }
    return 0;
}