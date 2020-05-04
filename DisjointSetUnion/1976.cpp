#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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
    int Same(int a, int b)
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

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    Dsu dsu(N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int in;
            cin >> in;
            if (in == 1)
            {
                dsu.Unite(i, j);
            }
            
        }
    }
    vector<int> traversal(M);
    for (int i = 0; i < M; ++i)
    {
        int in;
        cin >> in;
        --in;
        traversal[i] = in;
    }
    bool check = true;
    for (int i = 0; i < traversal.size() - 1; ++i)
    {
        if (dsu.Same(traversal[i], traversal[i + 1]) == false)
        {
            check = false;
            break;
        }
    }
    if (check == true)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}