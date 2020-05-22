#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int weight[26] = { 0, };
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int w = 1;
        string s;
        cin >> s;
        int sz = (int)s.size();
        for (int i = sz - 1; i >= 0; --i)
        {
            weight[s[i] - 'A'] += w;
            w *= 10;
        }
    }
    sort(weight, weight + 26, greater<int>());

    int sum = 0;
    for (int i = 0; i < 10; ++i)
        sum += weight[i] * (9 - i);
    cout << sum;
    
    return 0;
}