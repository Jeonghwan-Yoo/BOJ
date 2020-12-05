#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int price1, price2, price3, price4, price5;
    cin >> price1 >> price2 >> price3 >> price4 >> price5;
    cout << min({ price1, price2, price3 }) + min(price4, price5) - 50;

    return 0;
}