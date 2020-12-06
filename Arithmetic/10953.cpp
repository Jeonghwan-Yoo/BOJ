#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--)
    {
        char A, B;
        cin >> A >> B >> B;
        cout << A - '0' + B - '0' << '\n';
    }   

    return 0;
}