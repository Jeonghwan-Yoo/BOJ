#include <iostream>
#include <queue>

using namespace std;

#define INF 1e9

char maze[101][101];
int dist[101][101];
int N, M;
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

struct Graph
{
    int x, y, w;
    bool operator<(const Graph& a) const
    {
        return (w > a.w);
    }
};

void Dijkstra(int srcX, int srcY)
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            dist[i][j] = INF;
        }
    }
    dist[srcY][srcX] = 0;
    priority_queue<Graph> pq;
    pq.push({ srcX, srcY, 0 });
    while (!pq.empty())
    {
        int x = pq.top().x;
        int y = pq.top().y;
        int w = pq.top().w;
        pq.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 1 || nx > M || ny < 1 || ny > N)
            {
                continue;
            }
            if (dist[ny][nx] > maze[ny][nx] + w)
            {
                dist[ny][nx] = maze[ny][nx] + w;
                pq.push({ nx, ny, dist[ny][nx] });
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> maze[i][j];
            maze[i][j] -= '0';
        }
    }
    Dijkstra(1, 1);
    cout << dist[N][M];

    return 0;
}