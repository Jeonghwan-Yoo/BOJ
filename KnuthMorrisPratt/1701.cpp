#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getMaxFromFail(const string& s)
{
    int fail[5'001] = { 0, };
    int maxSz = 0;
    int m = (int)s.size();
    for (int i = 1, j = 0; i < m; ++i)
    {
        while (j > 0 && s[i] != s[j])
            j = fail[j - 1];
        if (s[i] == s[j])
        {
            ++j;
            fail[i] = j;
            maxSz = max(maxSz, j);
        }
    }
    return maxSz;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int maxSz = 0;
    int sz = (int)s.size();
    for (int i = 0; i < sz; ++i)
        maxSz = max(maxSz, getMaxFromFail(s.substr(i)));
    cout << maxSz;

    return 0;
}