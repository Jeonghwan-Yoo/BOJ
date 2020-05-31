#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_N 200'001
#define MAX_K 1'000'001

int N, K;
vector<pair<int, int> > adj[MAX_N];
int sz[MAX_N];
bool erased[MAX_N];
int dist[MAX_K];
int minDist = MAX_N;
vector<int> tmp;

int Dfs(int src, int parent)
{
    sz[src] = 1;
    for (auto &a : adj[src])
        if (a.first != parent && erased[a.first] == false)
            sz[src] += Dfs(a.first, src);
    return sz[src];
}

int Centroid(int src, int parent, int n)
{
    for (auto &a : adj[src])
        if (a.first != parent && erased[a.first] == false)
            if (sz[a.first] > n)
                return Centroid(a.first, src, n);    
    return src;
}

void Compute(int src, int parent, int weight, int depth)
{
    if (weight > K)
        return;
    minDist = min(minDist, dist[K - weight] + depth);
        
    for (auto &a : adj[src])
        if (a.first != parent && erased[a.first] == false)
            Compute(a.first, src, weight + a.second, depth + 1);
}

void Update(int src, int parent, int weight, int depth)
{
    if (weight > K)
        return;
    dist[weight] = min(dist[weight], depth);
    tmp.emplace_back(weight);

    for (auto &a : adj[src])
        if (a.first != parent && erased[a.first] == false)
            Update(a.first, src, weight + a.second, depth + 1);
}

void Decomposition(int src, int parent)
{
    int n = Dfs(src, parent);
    int c = Centroid(src, parent, n >> 1);
    erased[c] = true;
    for (int i = 0; i < (int)tmp.size(); ++i)
        dist[tmp[i]] = MAX_N;
    tmp.clear();
    dist[0] = 0;
    for (auto &a : adj[c])
    {
        if (erased[a.first] == false)
        {
            Compute(a.first, c, a.second, 1);
            Update(a.first, c, a.second, 1);
        }
    }
    for (auto &a : adj[c])
        if (erased[a.first] == false)
            Decomposition(a.first, c);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N - 1; ++i)
    {
        int h0, h1, l;
        cin >> h0 >> h1 >> l;
        adj[h0].emplace_back(h1, l);
        adj[h1].emplace_back(h0, l);
    }
    memset(dist, 0x7f, sizeof(dist));
    Decomposition(0, 0);
    if (minDist == MAX_N)
        minDist = -1;
    cout << minDist;

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <map>

// using namespace std;

// #define MAX_N 200'001

// int N, K;
// vector<pair<int, int> > adj[MAX_N];
// int sz[MAX_N];
// bool erased[MAX_N];
// map<int, int> dist;
// int minDist = MAX_N;

// int Dfs(int src, int parent)
// {
//     sz[src] = 1;
//     for (auto &a : adj[src])
//         if (a.first != parent && erased[a.first] == false)
//             sz[src] += Dfs(a.first, src);
//     return sz[src];
// }

// int Centroid(int src, int parent, int n)
// {
//     for (auto &a : adj[src])
//         if (a.first != parent && erased[a.first] == false)
//             if (sz[a.first] > n)
//                 return Centroid(a.first, src, n);    
//     return src;
// }

// void Compute(int src, int parent, int weight, int depth)
// {
//     if (weight > K)
//         return;
//     auto it = dist.find(K - weight);
//     if (it != dist.end())
//         minDist = min(minDist, it->second + depth);
        
//     for (auto &a : adj[src])
//         if (a.first != parent && erased[a.first] == false)
//             Compute(a.first, src, weight + a.second, depth + 1);
// }

// void Update(int src, int parent, int weight, int depth)
// {
//     if (weight > K)
//         return;
//     auto it = dist.find(weight);
//     if (it != dist.end())
//         it->second = min(it->second, depth);
//     else
//         dist[weight] = depth;
        
//     for (auto &a : adj[src])
//         if (a.first != parent && erased[a.first] == false)
//             Update(a.first ,src, weight + a.second, depth + 1);
// }

// void Decomposition(int src, int parent)
// {
//     int n = Dfs(src, parent);
//     int c = Centroid(src, parent, n >> 1);
//     erased[c] = true;
//     dist.clear();
//     dist[0] = 0;
//     for (auto &a : adj[c])
//     {
//         if (erased[a.first] == false)
//         {
//             Compute(a.first, c, a.second, 1);
//             Update(a.first, c, a.second, 1);
//         }
//     }
//     for (auto &a : adj[c])
//         if (erased[a.first] == false)
//             Decomposition(a.first, c);
// }

// int main()
// {
//     freopen("in.txt", "r", stdin);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> N >> K;
//     for (int i = 0; i < N - 1; ++i)
//     {
//         int h0, h1, l;
//         cin >> h0 >> h1 >> l;
//         adj[h0].emplace_back(h1, l);
//         adj[h1].emplace_back(h0, l);
//     }
//     Decomposition(0, 0);
//     if (minDist == MAX_N)
//         minDist = -1;
//     cout << minDist;

//     return 0;
// }