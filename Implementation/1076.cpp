#include <iostream>
#include <string>

using namespace std;

const string color[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};

int main()
{
    freopen("in.txt", "r", stdin);
    string tens;
    string units;
    string multiple;
    cin >> tens >> units >> multiple;
    long long ret = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (tens == color[i])
        {
            ret += i * 10;
        }
        if (units == color[i])
        {
            ret += i;
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        if (multiple == color[i])
        {
            for (int j = 0; j < i; ++j)
            {
                ret *= 10;
            }
        }
    }
    cout << ret;

    return 0;
}