#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string in;
    while (cin >> in)
    {
        if (in == "*")
            break;
        bool isUnique = true;
        for (int i = 0; i < (int)in.size() - 2; ++i)
        {
            unordered_set<string> str;
            for (int j = 0; j + i < in.size(); ++j)
            {
                string newStr = in.substr(j, 1) + in.substr(j + i + 1, 1);
                if (str.count(newStr) == 1)
                {
                    isUnique = false;
                    break;
                }
                str.insert(newStr);
            }
            if (isUnique == false)
            {
                break;
            }
        }
        cout << in << " is " << (isUnique ? "" : "NOT ") << "surprising.\n";
    }
    return 0;
}