#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (1)
    {
        bool check0 = false;
        unordered_map<string, string> name;
        unordered_set<string> banned;
        map<string, int> project;  
        string current;
        while (1)
        {
            string str;
            getline(cin, str);
            if ((str[0] == '1') || (str[0] == '0'))
            {
                check0 = (str[0] - '0') ^ 1;
                break;
            }
            if (banned.count(str) != 0)
            {
                continue;
            }
            if (islower(str[0]) == false)
            {
                current = str;
                project[current] = 0;
            }
            else
            {
                if (name.find(str) == name.end())
                {
                    name[str] = current;
                    ++project[current];
                }
                else
                {
                    if (name[str] != current)
                    {
                        banned.insert(str);
                        project[name[str]] -= 1;
                    }
                }
            }
        } 
        if (check0 == true)
        {
            break;
        }
        auto comp = [&](const pair<string, int> &a, const pair<string, int> &b) -> bool
        {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second > b.second;
        };
        auto sortedProject = set<pair<string, int>, decltype(comp)>(comp);
        for (auto const &p : project)
        {
            sortedProject.insert({ p.first, p.second });
        }
        for (auto const &s : sortedProject)
        {
            cout << s.first << ' ' << s.second << '\n';
        }
    }
    return 0;
}