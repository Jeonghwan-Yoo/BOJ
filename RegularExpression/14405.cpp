#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    regex re("pi|ka|chu");

    int len = 0;
    for (auto i = sregex_iterator(s.begin(), s.end(), re); i != sregex_iterator(); ++i)
        len += (int)i->str().size();

    if (len == (int)s.size())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}