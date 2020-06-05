#include <iostream>
#include <string>

using namespace std;

int fail[1'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string S, P;
    cin >> S >> P;
    int n = (int)S.size();
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
    bool match = false;
    for (int i = 0, j = 0; i < n; ++i)
    {
        while (j > 0 && S[i] != P[j])
            j = fail[j - 1];
        if (S[i] == P[j])
        {
            ++j;
            if (j == m)
            {
                match = true;
                break;
            }
        }
    }
    cout << (int)match;
    
    return 0;
}