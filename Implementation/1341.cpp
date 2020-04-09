#include <iostream>

using namespace std;

void divide(long long a, long long b)
{
    if (a == 0)
    {
        cout << "-";
        return;
    }
    if (a == b)
    {
        cout << "*";
        return;
    }
    if ((b & 1) == 0)
    {
        cout << "-1";
        return;
    }
    bool find = false;
    long long val = 1;
    long long cnt = 0;
    for (int i = 0; i < 60; ++i)
    {
        if (val % b == 0)
        {
            find = true;
            cnt = val / b;
            break;
        }
        val = (val << 1) + 1;
    }
    if (find == false)
    {
        cout << "-1";
        return;
    }
    b = b * cnt + 1;
    a = a * cnt;
    while (1)
    {
        b >>= 1;
        if (b < 1)
        {
            return;
        }
        if (a >= b)
        {
            cout << "*";
            a = a - b;
        } 
        else
        {
            cout << "-";
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    long long a, b;
    cin >> a >> b;
    divide(a, b);

    return 0;
}