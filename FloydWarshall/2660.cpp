#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 51

int adj[51][51];
int dist[51][51];
int score[51];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            adj[i][j] = INF;
    int a, b;
    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
            break;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            dist[i][j] = adj[i][j];
    
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            
    int minScore = INF;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                continue;
            score[i] = max(score[i], dist[i][j]);
        }
        minScore = min(minScore, score[i]);
    }
    vector<int> candidate;
    for (int i = 1; i <= N; ++i)
        if (score[i] == minScore)
            candidate.emplace_back(i);
    
    cout << minScore << ' ' << (int)candidate.size() << '\n';
    for (int i = 0; i < (int)candidate.size(); ++i)
        cout << candidate[i] << ' ';

    return 0;
}