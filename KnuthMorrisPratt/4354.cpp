#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int fail[1'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    while (cin >> s)
    {
        if (s == ".")
            break;
        memset(fail, 0, sizeof(fail));
        int m = (int)s.size();
        for (int i = 1, j = 0; i < m; ++i)
        {
            while (j > 0 && s[i] != s[j])
                j = fail[j - 1];
            if (s[i] == s[j])
            {
                ++j;
                fail[i] = j;
            }
        }
        int minSz = m - fail[m - 1];
        if (m % minSz == 0)
            cout << m / minSz << '\n';
        else
            cout << 1 << '\n';
    }
    
    return 0;
}