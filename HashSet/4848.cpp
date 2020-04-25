#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, int, greater<string> > bracket;
    bracket["{}"] = 0;
    for (int i = 1; i <= 15; ++i)
    {
        string str = "{";
        for (auto &b : bracket)
        {
            str += b.first;
            str += ",";
        }
        str.pop_back();
        str += "}";
        bracket[str] = i;
    }
    int T;
    cin >> T;
    while (T--)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        int sum = bracket[s1] + bracket[s2];
        for (auto &b : bracket)
        {
            if (b.second == sum)
            {
                cout << b.first << '\n';
                break;
            }
        }
    }
    
    return 0;
}