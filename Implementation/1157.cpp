#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int buf[26] = { 0, };
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] - 'a' >= 0)
            ++buf[str[i] - 'a'];
        else
            ++buf[str[i] - 'A'];
    }
    int maxCnt = 0;
    bool duplicated = false;
    int maxIdx = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (maxCnt < buf[i])
        {
            duplicated = false;
            maxCnt = buf[i];
            maxIdx = i;
        }
        else if (maxCnt == buf[i])
        {
            duplicated = true;
        }
    }
    if (duplicated)
    {
        cout << "?";
    }
    else
    {
        cout << static_cast<char>(maxIdx + 'A');
    }
    
    return 0;
}