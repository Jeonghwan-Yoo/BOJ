#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> pool[2'501];
int drain[2'501];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    N >>= 1;
    int x, y;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y >> x >> y;
        pool[i] = { x, y };
    }

    int K;
    cin >> K;
    int a, b, c;
    for (int i = 0; i < K; ++i)
    {
        cin >> a >> b >> c >> b;
        int l;
        for (int i = 0; i < N; ++i)
        {
            if (a == pool[i].first)
            {
                l = i;
                break;
            }
        }
        int r = l + 1;
        int minHeight = b;
        drain[l] = minHeight;
        --l;
        for (int j = l; j >= 0; --j)
        {
            if (pool[l].second < minHeight)
                minHeight = pool[l].second;
            if (drain[j] < minHeight)
                drain[j] = minHeight;
            else
                break;
            --l;
        }
        minHeight = b;
        for (int j = r; j < N; ++j)
        {
            if (pool[r].second < minHeight)
                minHeight = pool[r].second;
            if (drain[j] < minHeight)
                drain[j] = minHeight;
            else
                break;
            ++r;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < N - 1; ++i)
        sum += (pool[i].second - drain[i]) * (pool[i + 1].first - pool[i].first);
    cout << sum;

    return 0;
}