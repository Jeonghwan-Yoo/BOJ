#include <iostream>
#include <vector>
#include <algorithm>

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

    int N;
    cin >> N;
    vector<int> num(N);
    for (int i = 0; i < N; ++i)
        cin >> num[i];
    sort(num.begin(), num.end());

    int gcd = num[1] - num[0];
    for (int i = 2; i < N; ++i)
        gcd = Gcd(gcd, num[i] - num[i - 1]);

    vector<int> factor;
    for (int i = 2; i * i <= gcd; ++i)
    {
        if (gcd % i == 0)
        {
            factor.emplace_back(i);
            if (i * i != gcd)
                factor.emplace_back(gcd / i);
        }
    }
    factor.emplace_back(gcd);
    sort(factor.begin(), factor.end());
    int sz = (int)factor.size();
    for (int i = 0; i < sz; ++i)
        cout << factor[i] << ' ';

    return 0;
}