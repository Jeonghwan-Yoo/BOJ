#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int arr[100'001] = { 0, };
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    int sum[100'001 + 1] = { 0, };
    for (int i = 1; i <= N; ++i)
        sum[i] = sum[i - 1] + arr[i - 1];
    
    for (int m = 0; m < M; ++m)
    {
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << '\n';
    }
    
    return 0;
}