#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Trie
{
    Trie* node[26];
    bool terminal;
    Trie() : terminal(false)
    {
        memset(node, 0, sizeof(node));
    }
    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
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
            terminal = true;
        }
        else
        {
            int cur = *key - 'a';
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
            int cur = *key - 'a';
            if (node[cur] == nullptr)
            {
                return node[cur];
            }
            else
            {
                return node[cur]->Search(key + 1);
            }
            
        }
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    Trie* trie = new Trie();
    for (int i = 0; i < N; ++i)
    {
        string in;
        cin >> in;
        trie->Insert(in.c_str());
    }
    int cnt = 0;
    for (int i = 0; i < M; ++i)
    {
        string in;
        cin >> in;
        Trie* tmp = trie->Search(in.c_str());
        if (tmp == nullptr || tmp->terminal == false)
        {
            continue;
        }
        ++cnt;
    }
    cout << cnt;
    return 0;
}