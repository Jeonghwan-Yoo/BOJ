#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    string str;
    cin >> str;
    int alpha[26] = { 0, };
    int palin[50] = { 0, };
    int left = str.size();
    for (int i = 0; i < str.size(); ++i)
    {
        ++alpha[str[i] - 'A'];
    }
    for (int i = 0; i < 26; ++i)
    {
        cout << alpha[i] << ' ';
    }
    cout << '\n';
    if (str.size() & 1)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (alpha[i] & 1)
            {
                palin[str.size() >> 1] = i;
                --alpha[i];
                --left;
                break;
            }
        }
    }
    int cur = 0;
    while (left > 0)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (alpha[i] > 0)
            {
                palin[cur] = i;
                palin[str.size() - cur - 1] = i;
                alpha[i] -= 2;
                left -= 2;
                ++cur;
                break;
            }
        }
    }
    bool check = true;
    for (int i = 0; i < 26; ++i)
    {
        if (alpha[i] != 0)
        {
            check = false;
            break;
        }
    }
    if (check == false)
    {
        cout << "I'm Sorry Hansoo";
    }
    else
    {
        for (int i = 0; i < str.size(); ++i)
        {
            cout << static_cast<char>(palin[i] + 'A');
        }
    }
    return 0;
}