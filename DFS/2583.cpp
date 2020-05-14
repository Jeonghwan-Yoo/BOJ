#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int board[101][101] = { 0, };
int M, N, K;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int Dfs(int y, int x)
{
    board[y][x] = 1;
    int ret = 1;
    for (int dir = 0; dir < 4; ++dir)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= M || nx < 0 || nx >= N)
            continue;
        if (board[ny][nx] == 1)
            continue;
        ret += Dfs(ny, nx);
    }
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int y = y1; y < y2; ++y)
            for (int x = x1; x < x2; ++x)
                board[y][x] = 1;

    }
    vector<int> component;
    for (int y = 0; y < M; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (board[y][x] == 1)
                continue;
            component.push_back(Dfs(y, x));
        }
    }
    sort(component.begin(), component.end());
    cout << component.size() << '\n';
    for (int i = 0; i < component.size(); ++i)
        cout << component[i] << ' ';

    return 0;
}