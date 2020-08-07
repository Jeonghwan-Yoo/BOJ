#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string in;
    cin >> in;
    vector<string> sa;
    for (int i = 0; i < (int)in.size(); ++i)
        sa.emplace_back(in.substr(i));

    sort(sa.begin(), sa.end());

    for (auto &s : sa)
        cout << s << '\n';

    return 0;
}