#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<string, int> um;
    string name;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> name;
        ++um[name];
    }
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> name;
        --um[name];
    }
    for (auto &u : um)
        if (u.second > 0)
            cout << u.first;

    return 0;
}