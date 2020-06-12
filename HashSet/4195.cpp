#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Dsu
{
    vector<int> parent;
    vector<int> sz;
    Dsu(int n)
    {
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int Find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = Find(parent[x]);
    }
    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        if (a != b)
        {
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
    int GetSize(int x)
    {
        return sz[Find(x)];
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--)
    {
        int F;
        cin >> F;
        unordered_map<string, int> um;
        Dsu dsu(F << 1);
        string s1, s2;
        int idx = 0;
        for (int i = 0; i < F; ++i)
        {
            cin >> s1 >> s2;
            if (um.find(s1) == um.end())
            {
                um[s1] = idx;
                ++idx;
            }
            if (um.find(s2) == um.end())
            {
                um[s2] = idx;
                ++idx;
            }
            dsu.Union(um[s1], um[s2]);
            cout << dsu.GetSize(um[s1]) << '\n';
        }
    }

    return 0;
}