#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    string s;
    while (T--)
    {
        cin >> s;
        if (((int)s.size() & 1) == 1)
            s += s;
        string a;
        string b;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if ((i & 1) == 0)
                a += s[i];
            else
                b += s[i];
        }
        cout << a << '\n' << b << '\n';
    }

    return 0;
}