#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_VAL 1'000'000
#define MAX_N 1'000'000

int arr[MAX_N + 1];
int cnt[(MAX_VAL << 1) + 1];

void CountingSort(int n)
{
    for (int i = 0; i < n; ++i)
        ++cnt[arr[i]];

    int idx = 0;
    for (int i = 0; i <= (MAX_VAL << 1); ++i)
    {
        for (int j = 0; j < cnt[i]; ++j)
        {
            arr[idx] = i;
            ++idx;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        arr[i] += MAX_VAL;
    }
    
    CountingSort(N);
    for (int i = 0; i < N; ++i)
        cout << arr[i] - MAX_VAL << '\n';

    return 0;
}