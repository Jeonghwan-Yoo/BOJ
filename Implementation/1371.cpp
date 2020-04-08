#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char in;
    int alpha[26] = { 0, };
    while (cin >> in)
    {
        ++alpha[in - 'a'];
    }
    string res;
    int num = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (alpha[i] > num)
        {
            num = alpha[i];
            res = i + 'a';
        }
        else if (alpha[i] == num)
        {
            res += i + 'a';
        }
    }
    cout << res;

    return 0;
}