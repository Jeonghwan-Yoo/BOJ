#include <iostream>
#include <algorithm>

using namespace std;

int arr[5'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    
    nth_element(arr, arr + K - 1, arr + N);
    cout << arr[K - 1];

    return 0;
}