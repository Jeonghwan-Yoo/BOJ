#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int X2 = X << 1;
    int Y2 = Y << 1;
    int minCost;
    if (A + B >= (C << 1))
    {
        if (X >= Y)
        {
            minCost = C * Y2 + A * (X - Y);
            if (minCost > C * X2)
                minCost = C * X2;
        }
        else
        {
            minCost = C * X2 + B * (Y - X);
            if (minCost > C * Y2)
                minCost = C * Y2;
        }
    }
    else
        minCost = A * X + B * Y;

    cout << minCost;

    return 0;
}