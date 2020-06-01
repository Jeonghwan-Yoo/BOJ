#include <iostream>
#include <cstring>

using namespace std;

struct Trie
{
    Trie* node[10];
    int terminal;
    Trie() : terminal(0)
    {
        memset(node, 0, sizeof(node));        
    }
    ~Trie()
    {
        for (int i = 0; i < 10; ++i)
            if (node[i] != nullptr)
                delete node[i];
    }
    bool Insert(const char *key)
    {
        bool ret = true;
        if (*key == NULL)
        {
            if (terminal > 0)
                return false;
            terminal = 2;
        }
        else
        {
            int cur = *key - '0';
            if (node[cur] == nullptr)
                node[cur] = new Trie();
            if (node[cur]->terminal == 2)
                return false;
            terminal = 1;
            ret = node[cur]->Insert(key + 1);
        }
        return ret;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        Trie *trie = new Trie();
        int N;
        cin >> N;
        bool check = true;
        for (int n = 0; n < N; ++n)
        {
            char c[10] = { 0, };
            cin >> c;
            if (check == true)
                check = trie->Insert(c);
        }
        
        if (check == true)
            cout << "YES\n";
        else
            cout << "NO\n";
        delete trie;
    }
    return 0;
}