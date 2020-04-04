#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int A, B;
    cin >> A >> B;
    if (A > B)
        cout << ">";
    else if (A == B)
        cout << "==";
    else if (A < B)
        cout << "<";
    return 0;
}