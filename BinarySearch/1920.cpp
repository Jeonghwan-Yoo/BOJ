#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int arr[100'001] = { 0, };
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    sort(arr, arr + N);
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int in;
        cin >> in;
        cout << binary_search(arr, arr + N, in) << '\n';
    }
    return 0;
}