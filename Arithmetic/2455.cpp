#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int maxPeople = 0;
    int curPeople = 0;
    int off, on;
    while (cin >> off >> on)
    {
        if (on == 0)
            break;
        
        curPeople += on - off;
        if (maxPeople < curPeople)
            maxPeople = curPeople;
    }
    cout << maxPeople;

    return 0;
}