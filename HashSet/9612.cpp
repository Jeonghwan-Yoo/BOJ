#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    map<string, int> mp;
    string word;
    for (int i = 0; i < N; ++i)
    {
        cin >> word;
        ++mp[word];
    }
    string highestWord;
    int highestCnt = 0;
    for (auto &m : mp)
    {
        if (m.second >= highestCnt)
        {
            highestWord = m.first;
            highestCnt = m.second;
        }
    }
    cout << highestWord << ' ' << highestCnt;

    return 0;
}