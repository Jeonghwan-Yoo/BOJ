#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> Split(string str, int cut1, int cut2)
{
    vector<string> newOne(3);
    newOne[0] = str.substr(0, cut1 + 1);
    newOne[1] = str.substr(cut1 + 1, cut2 - cut1);
    newOne[2] = str.substr(cut2 + 1);
    return newOne;
}
void Reverse(string& str)
{
    for (int i = 0; i < (str.size() >> 1); ++i)
    {
        char tmp = str[i];
        str[i] = str[str.size() - 1 - i];
        str[str.size() - 1 - i] = tmp;
    }
}

string Compare(string& s1, string& s2)
{
    for (int i = 0; i < s1.size(); ++i)
    {
        if (s1[i] < s2[i])
        {
            return s1;
        }
        else if (s1[i] > s2[i])
        {
            return s2;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    string str;
    cin >> str;
    string ans(str.size(), 'z');
    for (int i = 0; i < str.size() - 1; ++i)
    {
        for (int j = i + 1; j < str.size() - 1; ++j)
        {
            vector<string> splited = Split(str, i, j);
            for (int k = 0; k < 3; ++k)
            {
                Reverse(splited[k]);
            }
            string newOne;
            for (int k = 0; k < 3; ++k)
            {
                newOne += splited[k];
            }
            ans = Compare(ans, newOne);
        }
    }
    cout << ans;
    return 0;
}