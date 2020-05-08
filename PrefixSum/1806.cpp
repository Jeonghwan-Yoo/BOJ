#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, S;
    cin >> N >> S;
    int arr[100'000] = { 0, };
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    int prefix[100'000 + 1] = { 0, };
    for (int i = 1; i <= N; ++i)
        prefix[i] = prefix[i - 1] + arr[i - 1];
    int length = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j + i <= N; ++j)
        {
            if (prefix[j + i] - prefix[j] >= S)
            {
                length = i;
                break;
            }
        }
        if (length != 0)
            break;
    }
    cout << length;
    return 0;
}