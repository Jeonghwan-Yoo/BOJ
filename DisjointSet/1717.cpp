#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class DisjointSet
{
public:
    int n;
    vector<int> link;
    DisjointSet(int _n) : n(_n)
    {
        link.resize(n);
        iota(link.begin(), link.end(), 0);
    }
    inline int Find(int x)
    {
        if (x == link[x])
            return x;
        return (link[x] = Find(link[x]));
    }
    inline bool Same(int a, int b)
    {
        return (Find(a) == Find(b));
    }
    inline void Unite(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        if (a != b)
            link[b] = a;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    DisjointSet ds(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0)
        {
            ds.Unite(a, b);
        }
        else if (op == 1)
        {
            if (ds.Same(a, b) == true)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    return 0;
}