#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int L, P;
    cin >> L >> P;
    int total = L * P;
    int num;
    for (int i = 0; i < 5; ++i)
    {
        cin >> num;
        cout << num - total << ' ';
    }   

    return 0;
}