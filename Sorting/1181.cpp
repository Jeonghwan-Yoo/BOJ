#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> str;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    str.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> str[i];
    
    sort(str.begin(), str.end(), [&str](string const &a, string const &b)
    {
        if ((int)a.size() == (int)b.size())
            return a < b;
        return (int)a.size() < (int)b.size();
    });
    str.erase(unique(str.begin(), str.end()), str.end());
    for (int i = 0; i < (int)str.size(); ++i)
        cout << str[i] << '\n';

    return 0;
}