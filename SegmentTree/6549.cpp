#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9

int N;
int tree[100'001 << 1];
int height[100'001];

void Build(int n)
{
    while (n >= 1)
    {
        if (height[tree[n << 1]] <= height[tree[n << 1 | 1]])
            tree[n] = tree[n << 1];
        else
            tree[n] = tree[n << 1 | 1];
        --n;
    }
}

int Query(int l, int r)
{   
    l += N;
    r += N;
    int minIdx = INF;
    int minVal = INF;
    while (l <= r)
    {
        if ((l & 1) == 1)
        {
            if (minVal >= height[tree[l]])
            {
                minIdx = tree[l];
                minVal = height[minIdx];
            }
            ++l;
        }
        if ((r & 1) == 0)
        {
            if (minVal >= height[tree[r]])
            {
                minIdx = tree[r];
                minVal = height[tree[r]];
            }
            --r;
        }
        l >>= 1;
        r >>= 1;
    }
    return minIdx;
}

long long MaxArea(int l, int r)
{
    if (l > r)
        return 0ll;
    if (l == r)
        return (long long)height[l];
    int minIdx = Query(l, r);
    return max({ (long long)(r - l + 1) * height[minIdx], MaxArea(l, minIdx - 1), MaxArea(minIdx + 1, r) });
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N)
    {
        if (N == 0)
            break;
        
        for (int i = 1; i <= N; ++i)
        {
            cin >> height[i];
            tree[i + N] = i;
        }

        Build(N);
        cout << MaxArea(1, N) << '\n';
    }
    return 0;
}