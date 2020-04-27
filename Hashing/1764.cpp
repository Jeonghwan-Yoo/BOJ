#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> unheard;
    set<string> both;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string in;
        cin >> in;
        unheard.push_back(in);
    } 
    sort(unheard.begin(), unheard.end());
    for (int i = 0; i < M; ++i)
    {
        string in;
        cin >> in;
        if (binary_search(unheard.begin(), unheard.end(), in))
            both.insert(in);
    }
    cout << both.size() << '\n';
    for (auto &b : both)
    {
        cout << b << '\n';
    }
    return 0;
}