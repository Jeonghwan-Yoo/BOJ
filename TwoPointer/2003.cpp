#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int arr[10001] = { 0, };
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    int p1 = 0;
    int p2 = 0;
    int cnt = 0;
    int sum = 0;
    while (p2 < N)
    {
        while (sum + arr[p2] <= M && p2 < N)
        {
            sum += arr[p2];
            ++p2;
        }
        if (sum == M)
            ++cnt;
        sum -= arr[p1];
        ++p1;
    }

    cout << cnt;
    return 0;
}