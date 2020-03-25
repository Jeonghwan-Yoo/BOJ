#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    int cnt = 0;
    while (cin >> str)
    {
        ++cnt;
    }
    cout << cnt;
    return 0;
}