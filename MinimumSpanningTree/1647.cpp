#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Graph
{
    int from, to, weight;
};
vector<Graph> edge;

struct Dsu
{
    int n;
    vector<int> parent;
    Dsu(int _n) : n(_n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
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
    void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        if (a != b)
            parent[b] = a;
    }
};

vector<Graph> Kruskal(int V)
{
    vector<Graph> mst;
    sort(edge.begin(), edge.end(), [&](const Graph &a, const Graph &b)
    {
        return a.weight < b.weight;
    });
    Dsu dsu(V);
    for (int i = 0; i < edge.size(); ++i)
    {
        int a = edge[i].from;
        int b = edge[i].to;
        int w = edge[i].weight;
        if (dsu.Same(a, b) == false)
        {
            dsu.Union(a, b);
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
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        --from;
        --to;
        edge.push_back({ from, to, weight });
    }
    vector<Graph> mst = Kruskal(N);
    int minCost = 0;
    for (int i = 0; i < mst.size(); ++i)
        minCost += mst[i].weight;
    cout << minCost - mst[mst.size() - 1].weight;

    return 0;
}