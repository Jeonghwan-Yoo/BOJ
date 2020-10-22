#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int sz = (int)s.size();
    for (int i = 0; i < sz; i += 10)
        cout << s.substr(i, 10) << '\n';

    return 0;
}