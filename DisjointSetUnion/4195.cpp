#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>

using namespace std;

struct Dsu
{
    int N;
    vector<int> parent;
    vector<int> sz;
    Dsu(int n) : N(n)
    {
        parent.resize(N << 1);
        sz.resize(N << 1);
        iota(parent.begin(), parent.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }
    int Find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = Find(parent[x]);
    }
    int Same(int a, int b)
    {
        return Find(a) == Find(b);
    }
    void Unite(int a, int b)
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
        unordered_map<string, int> friends;
        int F;
        cin >> F;
        Dsu dsu(F);
        int idx = 0;
        for (int i = 0; i < F; ++i)
        {
            string a, b;
            cin >> a >> b;
            if (friends.find(a) == friends.end())
            {
                friends[a] = idx;
                ++idx;
            }
            if (friends.find(b) == friends.end())
            {
                friends[b] = idx;
                ++idx;
            }
            int fa = friends[a];
            int fb = friends[b];
            dsu.Unite(fa, fb);
            cout << dsu.GetSize(fa) << '\n';            
        }
    }
    return 0;
}