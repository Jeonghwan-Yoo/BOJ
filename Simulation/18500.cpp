#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int constexpr dr[4] = { -1, 0, 1, 0 };
int constexpr dc[4] = { 0, 1, 0, -1 };

int R, C;
char board[101][101];
bool visited[101][101];

void GoingDown(vector<pair<int, int> > &cluster, int val)
{
    for (int i = 0; i < (int)cluster.size(); ++i)
        board[cluster[i].first][cluster[i].second] = '.';
    for (int i = 0; i < (int)cluster.size(); ++i)
        board[cluster[i].first + val][cluster[i].second] = 'x';
}

bool IsAttached(vector<pair<int, int> > &cluster, int r, int c)
{
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            visited[i][j] = false;
    
    cluster.emplace_back(r, c);
    visited[r][c] = true;
    queue<pair<int, int> > q;
    q.emplace(r, c);
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == R)
            return true;
        for (int dir = 0; dir < 4; ++dir)
        {
            pair<int, int> nxt = { cur.first + dr[dir], cur.second + dc[dir] };
            if (nxt.first <= 0 || nxt.first > R || nxt.second <= 0 || nxt.second > C)
                continue;
            if (board[nxt.first][nxt.second] == 'x' && visited[nxt.first][nxt.second] == false)
            {
                visited[nxt.first][nxt.second] = true;
                cluster.emplace_back(nxt);
                q.emplace(nxt);
            }
        }
    }
    return false;
}

int CalcDiff(vector<pair<int, int> > &cluster)
{
    int minDiff = R;
    for (int i = 0; i < (int)cluster.size(); ++i)
    {
        int diff = 0;
        for (int j = cluster[i].first + 1; j <= R; ++j)
        {
            if (visited[j][cluster[i].second] == true)
            {
                diff = R;
                break;
            }
            if (board[j][cluster[i].second] == 'x')
                break;
            ++diff;
        }
        minDiff = min(minDiff, diff);
    }

    return minDiff;
}

void Clustering(int r, int c)
{
    for (int dir = 0; dir < 4; ++dir)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (nr <= 0 || nr > R || nc <= 0 || nc > C)
            continue;
        if (board[nr][nc] == 'x')
        {
            vector<pair<int, int> > cluster;
            if (IsAttached(cluster, nr, nc) == false)
            {
                int minDiff = CalcDiff(cluster);
                GoingDown(cluster, minDiff);
                return;
            }
        }
    }
}

void ThrowStick(int right, int r)
{
    if (right == 0)
    {
        for (int c = 1; c <= C; ++c)
        {
            if (board[r][c] == 'x')
            {
                board[r][c] = '.';
                Clustering(r, c);
                return;
            }
        }
    }
    else
    {
        for (int c = C; c > 0; --c)
        { 
            if (board[r][c] == 'x')
            {
                board[r][c] = '.';
                Clustering(r, c);
                return;
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            cin >> board[i][j];

    int N;
    cin >> N;
    int height;
    for (int i = 0; i < N; ++i)
    {
        cin >> height;
        height = R - height + 1;
        ThrowStick(i & 1, height);
    }
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
            cout << board[i][j];
        cout << '\n';
    }

    return 0;
}