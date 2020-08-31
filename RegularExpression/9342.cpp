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
        string s;
        cin >> s;
        regex re("^[A-F]{0,1}A+F+C+[A-F]{0,1}?");
        
        if (regex_match(s, re))
            cout << "Infected!\n";
        else
            cout << "Good\n";
    }

    return 0;
}