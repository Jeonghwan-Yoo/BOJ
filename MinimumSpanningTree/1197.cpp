#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Graph
{
    int from, to, weight;
};
int V, E;

vector<Graph> edge;

class DisjointSet
{
public:
    int n;
    vector<int> parent;
    DisjointSet(int _n) : n(_n)
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
vector<Graph> Kruskal()
{
    vector<Graph> order;
    sort(edge.begin(), edge.end(), [&](const Graph &a, const Graph &b)
    {
        return a.weight < b.weight;
    });
    DisjointSet ds(V);
    for (int i = 0; i < edge.size(); ++i)
    {
        int from = edge[i].from;
        int to = edge[i].to;
        if (ds.Same(from, to) == false)
        {
            ds.Unite(from, to);
            order.push_back(edge[i]);
        }
    }
    return order;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    for (int e = 0; e < E; ++e)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        --from;
        --to;
        edge.push_back({ from, to, weight });
    }
    vector<Graph> mst = Kruskal();
    int sum = 0;
    for (int i = 0; i < mst.size(); ++i)
    {
        sum += mst[i].weight;    
    }
    cout << sum;
    return 0;
}