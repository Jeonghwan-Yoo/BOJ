#include <iostream>
#include <unordered_map>
#include <string>

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
        unordered_map<string, int> um;
        int N;
        cin >> N;
        string name, category;
        for (int i = 0; i < N; ++i)
        {
            cin >> name >> category;
            ++um[category];
        }
        int combination = 1;
        for (auto &u : um)
            combination *= u.second + 1;
        --combination;
        cout << combination << '\n';
    }

    return 0;
}