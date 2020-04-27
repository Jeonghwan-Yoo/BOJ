#include <iostream>
#include <vector>

using namespace std;

#define INF 1e18
vector<pair<int, int> > edge[101];
vector<long long> money;

void BellmanFord(int src, int V)
{
    for (int i = 0; i < (V << 1); ++i)
        for (int u = 0; u < V; ++u)
            for (auto &e : edge[u])
            {
                int a, b, w;
                a = u;
                b = e.first;
                w = e.second;
                if (money[a] == -INF) 
                    continue;
                else if (money[a] == INF)
                    money[b] = INF;
                else if (money[a] + w > money[b])
                    money[b] = (i < V) ? money[a] + w : INF;
            }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, A, B, M;
    cin >> N >> A >> B >> M;
    money.assign(N, -INF);
    for (int i = 0; i < M; ++i)
    {
        int s, e, w;
        cin >> s >> e >> w;
        edge[s].push_back({ e, -w });
    }
    for (int i = 0; i < N; ++i)
    {
        int getMoney;
        cin >> getMoney;
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < edge[j].size(); ++k)
                if (edge[j][k].first == i)
                    edge[j][k].second += getMoney;
        if (i == A)
            money[A] = getMoney;
    }
    BellmanFord(A, N);
    if (money[B] == -INF)
        cout << "gg";
    else if (money[B] == INF)
        cout << "Gee";
    else
        cout << money[B];
    
    return 0;
}