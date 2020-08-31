#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    bool flag = regex_match(s, regex("(100+1+|01)+"));
    if (flag)
        cout << "SUBMARINE\n";
    else
        cout << "NOISE\n";

    return 0;
}