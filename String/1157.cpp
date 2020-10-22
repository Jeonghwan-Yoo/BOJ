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
    int cnt[26] = { 0, };
    for (int i = 0; i < sz; ++i)
    {
        if (islower(s[i]))
            s[i] += 'A' - 'a';
        ++cnt[s[i] - 'A'];
    }
    int first = -1;
    int second = -1;
    for (int i = 0; i < 26; ++i)
    {
        if (first == -1 || cnt[i] > cnt[first])
        {
            second = first;
            first = i;
        }
        else if (second == -1 || cnt[i] > cnt[second])
            second = i;
    }
    cout << (first != second && cnt[first] == cnt[second] ? (char)'?' : (char)(first + 'A'));

    return 0;
}