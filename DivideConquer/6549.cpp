#include <iostream>
#include <algorithm>

using namespace std;

int N;
int height[100'001];

long long MaxArea(int l, int r)
{
    if (l == r)
        return height[l];

    int mid = (l + r) >> 1;
    int lr = mid;
    int rl = mid + 1; 
    long long maxArea = max(MaxArea(l, lr), MaxArea(rl, r));
    int minHeight = min(height[lr], height[rl]);
    maxArea = max(maxArea, (long long)minHeight << 1ll);

    while (l < lr || rl < r)
    {
        if (rl < r && (l == lr || height[lr - 1] < height[rl + 1]))
        {
            minHeight = min(minHeight, height[rl + 1]);
            ++rl;
        }
        else
        {
            minHeight = min(minHeight, height[lr - 1]);
            --lr;
        }
        maxArea = max(maxArea, (long long)(rl - lr + 1) * minHeight);
    }

    return maxArea;
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
            cin >> height[i];
        
        cout << MaxArea(1, N) << '\n';

    }
    return 0;
}