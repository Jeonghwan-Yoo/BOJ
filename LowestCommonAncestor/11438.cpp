#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100'001
#define LOG2MAX (int)(log2(MAX) + 1)

int N;
vector<int> adj[MAX];
vector<int> idx[(MAX << 1) - 1];
int depth[MAX];
int euler[(MAX << 1) - 1];
int pos;

void Dfs(int src, int parent, int d)
{
    depth[src] = d;
    ++pos;
    euler[pos] = src;
    idx[src].push_back(pos);
    for (auto &a : adj[src])
    {
        if (a != parent)
        {
            Dfs(a, src, d + 1);
            ++pos;
            euler[pos] = src;
            idx[src].push_back(pos);
        }
    }
}

int pow2[LOG2MAX];
int lg2[(MAX << 1) - 1];
pair<int, int> depthNode[LOG2MAX][(MAX << 1) - 1];

void SparseTable()
{
    pow2[0] = 1;
    for (int i = 1; i < LOG2MAX; ++i)
        pow2[i] = pow2[i - 1] << 1;

    for (int i = 0; i < LOG2MAX; ++i)
        lg2[pow2[i]] = i;
    for (int i = 1; i < (MAX << 1) - 1; ++i)
        if (lg2[i] == 0)
            lg2[i] = lg2[i - 1];

    for (int i = 1; i <= (N << 1) - 1; ++i)
        depthNode[0][i] = { depth[euler[i]], euler[i] };
    for (int i = 1; i < LOG2MAX; ++i)
        for (int j = 1; j <= (N << 1) - 1; ++j)
            depthNode[i][j] = min(depthNode[i - 1][j], depthNode[i - 1][j + pow2[i - 1]]);
}

int Lca(int a, int b)
{
    int l = idx[a][0];
    int r = idx[b][0];
    if (l > r)
        swap(l, r);

    int sz = lg2[r - l + 1];
    return min(depthNode[sz][l], depthNode[sz][r - pow2[sz] + 1]).second;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    Dfs(1, 0, 0);
    SparseTable();

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << Lca(a, b) << '\n';
    }
    return 0;
}
