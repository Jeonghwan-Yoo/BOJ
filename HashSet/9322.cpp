#include <iostream>
#include <unordered_map>
#include <vector>

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
        vector<int> v;
        int N;
        cin >> N;
        string str;
        for (int i = 0; i < N; ++i)
        {
            cin >> str;
            um[str] = i;
        }
        for (int i = 0; i < N; ++i)
        {
            cin >> str;
            v.emplace_back(um[str]);
        }
        vector<string> plaintext(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> str;
            plaintext[v[i]] = str;
        }
        for (int i = 0; i < N; ++i)
            cout << plaintext[i] << ' ';
        cout << '\n';
    }

    return 0;
}