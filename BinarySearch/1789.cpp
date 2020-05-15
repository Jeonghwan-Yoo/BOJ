#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long S;
    cin >> S;
    int l = 0;
    int r = 100'000;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        long long sum = 0;
        for (int i = 1; i <= mid; ++i)
            sum += i;
        if (sum <= S)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r;
    
    return 0;
}