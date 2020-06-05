#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fail[1'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, P;
    getline(cin, T);
    getline(cin, P);
    int n = (int)T.size();
    int m = (int)P.size();
    for (int i = 1, j = 0; i < m; ++i)
    {
        while (j > 0 && P[i] != P[j])
            j = fail[j - 1];
        if (P[i] == P[j])
        {
            ++j;
            fail[i] = j;
        }
    }
    vector<int> match;
    for (int i = 0, j = 0; i < n; ++i)
    {
        while (j > 0 && T[i] != P[j])
            j = fail[j - 1];
        if (T[i] == P[j])
        {
            ++j;
            if (j == m)
            {
                match.emplace_back(i - j + 2);
                j = fail[j - 1];
            }
        }
    }
    cout << (int)match.size() << '\n';
    for (int i = 0; i < (int)match.size(); ++i)
        cout << match[i] << ' ';

    return 0;
}