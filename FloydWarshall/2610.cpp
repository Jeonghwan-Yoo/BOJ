#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 101

int adj[101][101];
int dist[101][101];
int visited[101];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (adj[i][j] == 0 || i == j)
                dist[i][j] = INF;
            else
                dist[i][j] = adj[i][j];
        }
    }
    
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (i == j)
                     continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    vector<int> representative;
    queue<int> q;
    for (int i = 1; i <= N; ++i)
    {
        int candidate = i;
        int maxVal = INF;
        if (visited[i] == false)
        {
            q.emplace(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                int val = 0;
                for (int j = 1; j <= N; ++j)
                {
                    if (dist[cur][j] > val && dist[cur][j] < INF)
                        val = dist[cur][j];
                    if (visited[j] == false && dist[cur][j] < INF)
                    {
                        visited[j] = true;
                        q.emplace(j);
                    }
                }
                if (maxVal > val)
                {
                    maxVal = val;
                    candidate = cur;
                }
            }
            representative.emplace_back(candidate);
        }
    }
    sort(representative.begin(), representative.end());

    cout << (int)representative.size() << '\n';
    for (int i = 0; i < (int)representative.size(); ++i)
        cout << representative[i] << '\n';

    return 0;
}