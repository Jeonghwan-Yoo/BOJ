#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    regex re("problem", regex::icase);
    string s;
    while (getline(cin, s))
    {
        bool flag = false;
        for (auto i = sregex_iterator(s.begin(), s.end(), re); i != sregex_iterator(); ++i)
            flag = true;
        
        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}