#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9

int arr[300'001];
int minSzArr[300'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, N;
    cin >> D >> N;
    int minSz = INF;
    for (int i = 1; i <= D; ++i)
    {
        cin >> arr[i];
        minSz = min(minSz, arr[i]);
        minSzArr[i] = minSz;
    }

    int depth = D;
    int sz;
    for (int i = 0; i < N; ++i)
    {
        cin >> sz;
        if (depth == -1)
            continue;
        while (depth > 0 && minSzArr[depth] < sz)
            --depth;
        --depth;
    }
    cout << depth + 1;

    return 0;
}