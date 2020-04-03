#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    string in;
    while (1)
    {
        cin >> in;
        if (in == "0")
        {
            break;
        }
        bool check = true;
        for (int i = 0; i < (in.size() >> 1); ++i)
        {
            if (in[i] != in[in.size() - 1 - i])
            {
                check = false;
                break;
            }
        }
        if (check == true)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';

    }
    return 0;
}