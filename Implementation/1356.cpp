#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    string in;
    cin >> in;
    bool yoojin = false;
    for (int i = 1; i < in.size(); ++i)
    {
        string left = in.substr(0, i);
        string right = in.substr(i);
        int leftVal = 1;
        int rightVal = 1;
        for (int j = 0; j < left.size(); ++j)
        {
            leftVal *= left[j] - '0';
        }
        for (int j = 0; j < right.size(); ++j)
        {
            rightVal *= right[j] - '0';
        }
        if (leftVal == rightVal)
        {
            yoojin = true;
            break;
        }
    }
    if (yoojin == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}