#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> unheard;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> both;
    int N, M;
    cin >> N >> M;
    unheard.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> unheard[i];
        
    sort(unheard.begin(), unheard.end());

    string unseen;
    for (int i = 0; i < M; ++i)
    {
        cin >> unseen;
        if (binary_search(unheard.begin(), unheard.end(), unseen))
            both.emplace_back(unseen);
    }
    sort(both.begin(), both.end());
    cout << both.size() << '\n';
    for (auto &b : both)
        cout << b << '\n';

    return 0;
}