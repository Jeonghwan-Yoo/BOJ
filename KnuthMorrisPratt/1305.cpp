#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int fail[1'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    cin >> L;
    string ad;
    cin >> ad;    
    for (int i = 1, j = 0; i < L; ++i)
    {
        while (j > 0 && ad[i] != ad[j])
            j = fail[j - 1];
        if (ad[i] == ad[j])
        {
            ++j;
            fail[i] = j;
        }
    }
    cout << L - fail[L - 1];

    return 0;
}