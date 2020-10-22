#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt[26];
    for (int i = 0; i < 26; ++i)
        cnt[i] = -1;
    string s;
    cin >> s;
    for (int i = (int)s.size() - 1; i >= 0; --i)
        cnt[s[i] - 'a'] = i;
    for (int i = 0; i < 26; ++i)
        cout << cnt[i] << ' ';

    return 0;
}