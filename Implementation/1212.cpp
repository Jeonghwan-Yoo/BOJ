#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string oct;
    cin >> oct;
    bool findFirst1 = false;
    for (int i = 0; i < oct.size(); ++i)
    {
        int bin = oct[i] - '0';
        string str;
        for (int i = 0; i < 3; ++i)
        {
            str += to_string(bin & 1);
            bin >>= 1;
        }
        swap(str[0], str[2]);
        if (findFirst1 == true)
        {
            cout << str;
        }
        else 
        {
            for (int i = 0; i < 3; ++i)
            {
                if (findFirst1 == true)
                {
                    cout << str[i];
                }
                else if (str[i] - '0' == 1)
                {
                    findFirst1 = true;
                    cout << str[i];
                }
            }
        }
    }
    if (findFirst1 == false)
    {
        cout << "0";
    }
    return 0;
}