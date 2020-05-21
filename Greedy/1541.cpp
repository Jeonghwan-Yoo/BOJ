#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    bool findMinus = false;
    int num;
    char c;
    cin >> num;
    int sum = num;
    while (cin >> c)
    {
        cin >> num;
        int num2 = num;
        if (c == '+' && findMinus == false)
            sum += num2;
        else
        {
            sum -= num2;
            findMinus = true;
        }
    }
    cout << sum;

    return 0;
}