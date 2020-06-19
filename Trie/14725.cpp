#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Trie
{
    map<string, Trie> node;
    void Add(const vector<string> &key, int idx)
    {
        if (idx == (int)key.size())
            return;
        else
            node[key[idx]].Add(key, idx + 1);
    }
    void Search(int src)
    {
        for (auto &n : node)
        {
            for (int i = 0; i < src; ++i)
                cout << "--";
            cout << n.first << '\n';
            node[n.first].Search(src + 1);
        }
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    Trie trie;
    for (int n = 0; n < N; ++n)
    {
        int K;
        cin >> K;
        vector<string> v(K);
        for (int k = 0; k < K; ++k)
            cin >> v[k];
        trie.Add(v, 0);
    }
    trie.Search(0);

    return 0;
}