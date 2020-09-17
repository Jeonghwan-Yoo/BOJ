#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<vector<char> > board(N, vector<char>(N + 1));    
    vector<vector<int> > visited(N, vector<int>(N));    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    vector<int> house;
    queue<pair<int, int> > q;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!visited[i][j])
            {
                visited[i][j] = 1;
                if (board[i][j] == '1')
                {
                    int cnt = 0;
                    q.emplace(j, i);
                    while (!q.empty())
                    {
                        int cx = q.front().first;
                        int cy = q.front().second;
                        ++cnt;
                        q.pop();
                        for (int dir = 0; dir < 4; ++dir)
                        {
                            int nx = cx + dx[dir];
                            int ny = cy + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                                continue;
                            
                            if (!visited[ny][nx])
                            {
                                visited[ny][nx] = 1;
                                if (board[ny][nx] == '1')
                                    q.emplace(nx, ny);
                            }

                        }
                    }
                    house.emplace_back(cnt);
                }
            }
        }
    }
    sort(house.begin(), house.end());
    cout << (int)house.size() << '\n';
    for (int i = 0; i < (int)house.size(); ++i)
        cout << house[i] << '\n';

    return 0;
}