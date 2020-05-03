#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

struct Pos
{
    int idx;
    int x, y, z;
};

struct Graph
{
    int a, b, w;
};

vector<Pos> tunnel;
vector<Graph> edge;

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
            parent[b] = a;
    }
};

vector<Graph> Kruskal(int N)
{
    vector<Graph> mst;
    sort(edge.begin(), edge.end(), [&edge](const Graph &a, const Graph &b)
    {
        return a.w < b.w;
    });
    Dsu dsu(N);
    for (int i = 0; i < edge.size(); ++i)
    {
        int a = edge[i].a;
        int b = edge[i].b;
        if (dsu.Same(a, b) == false)
        {
            dsu.Unite(a, b);
            mst.push_back(edge[i]);
        }
    }
    return mst;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tunnel.push_back({ i, x, y, z });
    }

    sort(tunnel.begin(), tunnel.end(), [&tunnel](const Pos &a, const Pos &b)
    {
        return a.x < b.x;
    });
    for (int i = 0; i < N - 1; ++i)
    {
        edge.push_back({ tunnel[i].idx, tunnel[i + 1].idx, abs(tunnel[i].x - tunnel[i + 1].x) });
    }
    sort(tunnel.begin(), tunnel.end(), [&tunnel](const Pos &a, const Pos &b)
    {
        return a.y < b.y;
    });
    for (int i = 0; i < N - 1; ++i)
    {
        edge.push_back({ tunnel[i].idx, tunnel[i + 1].idx, abs(tunnel[i].y - tunnel[i + 1].y) });
    }
    sort(tunnel.begin(), tunnel.end(), [&tunnel](const Pos &a, const Pos &b)
    {
        return a.z < b.z;
    });
    for (int i = 0; i < N - 1; ++i)
    {
        edge.push_back({ tunnel[i].idx, tunnel[i + 1].idx, abs(tunnel[i].z - tunnel[i + 1].z) });
    }
    long long total = 0;
    vector<Graph> mst = Kruskal(N);
    for (int i = 0; i < mst.size(); ++i)
        total += mst[i].w;
    cout << total;

    return 0;
}
