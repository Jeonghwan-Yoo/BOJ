#include <iostream>
#include <regex>
#include <string>

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
        string s;
        cin >> s;
        bool flag = regex_match(s, regex("(100+1+|01)+"));
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}