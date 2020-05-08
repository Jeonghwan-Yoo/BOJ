#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>

using namespace std;

struct Trie
{
    Trie *alpha[26] = { 0, };
    int cnt = 0;
    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
            if (alpha[i] != nullptr)
                delete alpha[i];
    }
    void Insert(const char *key)
    {
        if (*key == NULL)
            return;
        else
        {
            int cur = *key - 'a';
            if (alpha[cur] == nullptr)
                alpha[cur] = new Trie();
            alpha[cur]->Insert(key + 1);
            ++alpha[cur]->cnt;
        }
    }
    int Press(const char *key)
    {
        if (*key == NULL)
            return 0;
        else
        {
            int cur = *key - 'a';
            if (alpha[cur] == nullptr)
                return 0;
            else
            {
                if (alpha[cur]->cnt == cnt)
                    return alpha[cur]->Press(key + 1);
                else
                    return alpha[cur]->Press(key + 1) + 1;
            }
        }
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while (cin >> N)
    {
        Trie *trie = new Trie();
        vector<string> words(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> words[i];
            trie->Insert(words[i].c_str());
        }
        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += trie->Press(words[i].c_str());
        cout << fixed << setprecision(2) << (double)sum / N << '\n';
        delete trie;
    }
    return 0;
}