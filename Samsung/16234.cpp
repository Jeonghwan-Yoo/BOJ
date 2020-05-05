#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int board[51][51];

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L, R;
    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    int cnt = 0;
    while (1)
    {
        bool update = false;
        bool visited[51][51] = { false, };
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (visited[i][j] == true)
                    continue;
                visited[i][j] = true;
                queue<pair<int, int> > q;
                vector<pair<int, int> > group;
                q.push({ j, i });
                group.push_back({ j, i });
                int sum = board[i][j];
                while (q.empty() == false)
                {
                    int curX = q.front().first;
                    int curY = q.front().second;
                    q.pop();
                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nxtX = curX + dx[dir];
                        int nxtY = curY + dy[dir];
                        if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= N)
                            continue;
                        if (visited[nxtY][nxtX] == true)
                            continue;
                        int diff = abs(board[nxtY][nxtX] - board[curY][curX]); 
                        if (L <= diff && diff <= R)
                        {
                            visited[nxtY][nxtX] = true;
                            q.push({ nxtX, nxtY });
                            group.push_back({ nxtX, nxtY });
                            sum += board[nxtY][nxtX];
                            update = true;
                        }
                    }
                }
                if (group.size() > 1)
                {
                    int avg = sum / group.size();
                    for (int k = 0; k < group.size(); ++k)
                        board[group[k].second][group[k].first] = avg;
                }
            }
        }
        if (update == false)
            break;
        ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}