#include <iostream>
#include <string>
#include <cstring>
#include <unordered_set>

using namespace std;

constexpr int score[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };
constexpr int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
constexpr int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

char board[4][5];
bool visited[4][4];
unordered_set<string> got;

struct Trie
{
    Trie *node[26];
    int terminal;
    Trie() : terminal(0)
    {
        memset(node, 0, sizeof(node));
    }
    ~Trie()
    {
        for (int i = 0; i < 26; ++i)
            if (node[i] != nullptr)
                delete node[i];
    }
    void Add(const char *key)
    {
        if (*key == NULL)
            terminal = 1;
        else
        {
            int cur = *key - 'A';
            if (node[cur] == nullptr)
                node[cur] = new Trie();
            node[cur]->Add(key + 1);
        }
    }
    void Search(int x, int y, string &s)
    {
        visited[y][x] = true;
        s += board[y][x];
        int cur = board[y][x] - 'A';
        if (node[cur] == nullptr)
        {
            visited[y][x] = false;
            s.pop_back();
            return;
        }
        if (node[cur]->terminal == 1)
            got.insert(s);
        for (int dir = 0; dir < 8; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4)
                continue;
            if (visited[ny][nx] == true)
                continue;
            node[cur]->Search(nx, ny, s);
        }
        s.pop_back();
        visited[y][x] = false;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    cin >> w;
    Trie *trie = new Trie();
    string in;
    for (int i = 0; i < w; ++i)
    {
        cin >> in;
        trie->Add(in.c_str());
    }

    int b;
    cin >> b;
    for (int i = 0; i < b; ++i)
    {
        got.clear();
        for (int j = 0; j < 4; ++j)
            cin >> board[j];
        
        string s;
        for (int y = 0; y < 4; ++y)
            for (int x = 0; x < 4; ++x)
                trie->Search(x, y, s);

        int sum = 0;
        string longest = *got.begin();
        for (auto &g : got)
        {
            sum += score[g.size()];
            if ((int)g.size() == (int)longest.size() && g < longest)
                longest = g;
            else if ((int)g.size() > (int)longest.size())
                longest = g;
        }
        cout << sum << ' ' << longest << ' ' << got.size() << '\n';
    }
    delete trie;

    return 0;
}