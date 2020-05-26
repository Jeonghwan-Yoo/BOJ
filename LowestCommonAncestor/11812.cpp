#include <iostream>
#include <algorithm>

using namespace std;

long long GetParent(long long val, int k)
{
    return (val + k - 2) / k;
}

long long Diff(long long a, long long b, int k)
{
    if (a > b)
        swap(a, b);

    if (k == 1)
        return (b - a);

    long long diff = 0;
    while (a != b)
    {
        while (a < b)
        {
            b = GetParent(b, k);
            ++diff;
        }
        while (a > b)
        {
            a = GetParent(a, k);
            ++diff;
        }
    }
    return diff;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N;
    int K, Q;
    cin >> N >> K >> Q;
    for (int i = 0; i < Q; ++i)
    {
        long long x, y;
        cin >> x >> y;
        cout << Diff(x, y, K) << '\n';
    }
    
    return 0;
}