#include <iostream>

using namespace std;

#define MAX 100000

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, S;
    cin >> N >> S;
    int arr[MAX] = { 0, };
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    int l = 0;
    int r = 0;
    int minLength = MAX;
    int sum = 0;
    while (l < N)
    {
        while (r < N && sum < S && r - l + 1 < minLength)
        {
            sum += arr[r];
            ++r;
        }
        if (sum >= S)
        {
            if (minLength > r - l)
                minLength = r - l;
        }
        sum -= arr[l];
        ++l;
    }
    if (minLength == MAX)
        cout << 0;
    else
        cout << minLength;
    
    return 0;
}