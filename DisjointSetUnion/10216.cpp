#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

struct Dsu
{
    vector<int> parent;
    int N;
    Dsu(int n) : N(n)
    {
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
    }
    int Find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = Find(parent[x]);
    }
    bool Same(int a, int b)
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
        }
    }
    int GetGroup()
    {
        set<int> s;
        for (int i = 0; i < parent.size(); ++i)
        {
            s.insert(Find(parent[i]));            
        }
        return s.size();
    }
};

struct Tower
{
    int x, y, r;
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
        int N;
        cin >> N;
        Dsu dsu(N);
        vector<Tower> tower(N);
        for (int i = 0; i < N; ++i)
        {
            int x, y, r;
            cin >> x >> y >> r;
            tower[i] = { x, y, r };
        }
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                if ((tower[i].x - tower[j].x) * (tower[i].x - tower[j].x) + (tower[i].y - tower[j].y) * (tower[i].y - tower[j].y) <= (tower[i].r + tower[j].r) * (tower[i].r + tower[j].r))
                {
                    dsu.Unite(i, j);
                }
            }
        }
        cout << dsu.GetGroup() << '\n';
    }
    return 0;
}