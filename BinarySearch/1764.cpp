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
    
    int N, M;
    cin >> N >> M;
    vector<string> unheard(N);
    for (int i = 0; i < N; ++i)
        cin >> unheard[i];
    sort(unheard.begin(), unheard.end());

    string unseen;
    vector<string> both;
    for (int i = 0; i < M; ++i)
    {
        cin >> unseen;
        if (binary_search(unheard.begin(), unheard.end(), unseen))
            both.emplace_back(unseen);
    }
    sort(both.begin(), both.end());
    cout << (int)both.size() << '\n';
    for (int i = 0; i < (int)both.size(); ++i)
        cout << both[i] << '\n';

    return 0;
}