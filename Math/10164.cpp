#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Combination(int sy, int sx, int ey, int ex)
{
    int diffY = ey - sy;
    int diffX = ex - sx;
    int smaller = min(diffY, diffX);
    int bigger = max(diffY, diffX);
    int sumDiff = diffY + diffX;
    long long ret = 1ll;
    for (int i = sumDiff; i > bigger; --i)
        ret *= i;
    for (int i = smaller; i >= 2; --i)
        ret /= i;

    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    if (K != 0)
        --K;
    int r = K / M;
    int c = K % M;
    long long before = Combination(0, 0, r, c);
    long long after = Combination(r, c, N - 1, M - 1);
    cout << before * after;

    return 0;
}