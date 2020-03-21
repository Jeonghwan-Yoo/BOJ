#include <iostream>
#include <algorithm>

using namespace std;

int N;
int pay[2][15];
int cache[15];

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> pay[0][i] >> pay[1][i];
    }
    for (int i = 0; i < N; ++i)
    {
        if (i + pay[0][i] <= N)
            cache[i + pay[0][i]] = max(cache[i + pay[0][i]], cache[i] + pay[1][i]);
        cache[i + 1] = max(cache[i + 1], cache[i]);
    }
    cout << cache[N];
    return 0;
}