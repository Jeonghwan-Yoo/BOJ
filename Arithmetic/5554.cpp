#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sum = 0;
    int num;
    for (int i = 0; i < 4; ++i)
    {
        cin >> num;
        sum += num;
    }
    cout << sum / 60 << '\n' << sum % 60;

    return 0;
}