#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int X;
    cin >> X;
    int n = 1;
    int sum = n;
    while (1)
    {
        if (sum >= X)
        {
            int dividend;
            int divisor;
            if (n & 1)
            {
                dividend = sum - X + 1;
                divisor = n - dividend + 1;
            }
            else
            {
                divisor = sum - X + 1;
                dividend = n - divisor + 1;
            }
            cout << dividend << '/' << divisor;
            break;
        }
        ++n;
        sum = (n * (n + 1) >> 1); 
    }
    
    return 0;
}