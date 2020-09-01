#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int cnt = 0;
        int pos = s1.find('_');
        char c = 0;
        for (int i = 0; i < 26; ++i)
        {
            s1[pos] = i + 'A';
            regex re(s1);
            if (regex_match(s2, re))
            {
                ++cnt;
                c = s1[pos];
            }
        }
        if (cnt == 0)
            cout << "!\n";
        else if (cnt == 1)
            cout << c << '\n';
        else
            cout << "_\n";
    }

    return 0;
}