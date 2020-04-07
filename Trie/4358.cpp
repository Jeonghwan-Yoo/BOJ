#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Trie
{
    Trie* node[128];
    int cnt = 0;

    Trie()
    {
        memset(node, 0, sizeof(node));
    }
    ~Trie()
    {
        for (int i = 0; i < 128; ++i)
        {
            if (node[i] != nullptr)
            {
                delete node[i];
            }
        }
    }
    void Insert(const char *key)
    {
        if (*key == NULL)
        {
            ++cnt;
        }
        else
        {
            int cur = *key;
            if (node[cur] == nullptr)
            {
                node[cur] = new Trie();
            }
            node[cur]->Insert(key + 1);
        }
    }
    Trie* Search(const char *key)
    {
        if (*key == NULL)
        {
            return this;
        }
        else
        {
            int cur = *key;
            if (node[cur] == nullptr)
            {
                return node[cur];
            }
            return node[cur]->Search(key + 1);
        }
    }

};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Trie* trie = new Trie();
    string in;
    vector<string> tree;
    int total = 0;
    while (getline(cin, in))
    {
        ++total;
        Trie* tmp;
        if ((tmp = trie->Search(in.c_str())) == nullptr)
        {
            tree.push_back(in);
            trie->Insert(in.c_str());
        }
        else
        {
            tmp->cnt += 1;
        }
    }
    sort(tree.begin(), tree.end());
    for (int i = 0; i < tree.size(); ++i)
    {
        Trie* tmp;
        tmp = trie->Search(tree[i].c_str());
        cout << fixed << setprecision(4) << tree[i] << ' ' << static_cast<double>(tmp->cnt) / total * 100 << '\n';
    }

    return 0;
}
