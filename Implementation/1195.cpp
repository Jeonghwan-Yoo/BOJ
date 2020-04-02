#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    string s1;
    string s2;
    cin >> s1 >> s2;
    string bigger = s1.size() >= s2.size() ? s1 : s2;
    string smaller = s1.size() < s2.size() ? s1 : s2;
    string blank;
    for (int i = 0; i < smaller.size(); ++i)
    {
        blank += "1";
    }
    string extend = blank + bigger + blank;
    int minLen = bigger.size() + smaller.size();
    int cur = 0;
    while (1)
    {
        if (cur > bigger.size() + smaller.size())
        {
            break;
        }
        bool check = true;
        for (int i = 0; i < bigger.size(); ++i)
        {
            if (extend[i + cur] == '2' && smaller[i] == '2')
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            int len = bigger.size();
            if (cur < blank.size())
            {
                len += blank.size() - cur;
            }
            else if (cur + smaller.size() > blank.size() + bigger.size())
            {
                len += cur + smaller.size() - (blank.size() + bigger.size());
            }
            minLen = min(minLen, len);
        }
        ++cur;
    }
    cout << minLen;

    return 0;
}