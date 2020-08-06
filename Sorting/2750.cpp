#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[1'001];
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    
    sort(arr, arr + N);
    for (int i = 0; i < N; ++i)
        cout << arr[i] << '\n';

    return 0;
}