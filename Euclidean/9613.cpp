#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> num(n);
        for (int i = 0; i < n; ++i)
            cin >> num[i];
        
        long long sum = 0ll;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int a = num[i];
                int b = num[j];
                if (a < b)
                    swap(a, b);
                sum += (long long)Gcd(a, b);
            }
        }
        cout << sum << '\n';
    }

    return 0;
}