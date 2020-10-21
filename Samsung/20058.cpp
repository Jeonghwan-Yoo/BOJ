#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int constexpr dy[4] = { -1, 0, 1, 0 };
int constexpr dx[4] = { 0, 1, 0, -1 };

int NN;

void Rotate(int level, int y, int x, int d, int sz, vector<vector<vector<int>>> &board)
{
    if (level == 0)
    {
        for (int i = y; i < y + sz; ++i)
        {
            for (int j = x; j < x + sz; ++j)
            {
                int ny = i + dy[d] * sz;
                int nx = j + dx[d] * sz;
                board[1][ny][nx] = board[0][i][j];
            }
        }
        return;
    }

    int nsz = sz >> 1;
    int nlevel = level - 1;
    Rotate(nlevel, y, x, 1, nsz, board);
    Rotate(nlevel, y, x + nsz, 2, nsz, board);
    Rotate(nlevel, y + nsz, x + nsz, 3, nsz, board);
    Rotate(nlevel, y + nsz, x, 0, nsz, board);
}

void CopyToOriginal(vector<vector<vector<int>>> &board)
{
    for (int i = 0; i < NN; ++i)
        for (int j = 0; j < NN; ++j)
            board[0][i][j] = board[1][i][j];
}

void Melt(vector<vector<int>> &board)
{
    vector<pair<int, int>> candidate;
    for (int i = 0; i < NN; ++i)
    {
        for (int j = 0; j < NN; ++j)
        {
            if (board[i][j] == 0)
                continue;

            int adj = 0;
            for (int d = 0; d < 4; ++d)
            {
                int ny = i + dy[d];
                int nx = j + dx[d];
                if (ny < 0 || ny >= NN || nx < 0 || nx >= NN || board[ny][nx] == 0)
                    continue;
                
                ++adj;
            }

            if (adj < 3)
                candidate.emplace_back(i, j);
        }
    }
    int sz = (int)candidate.size();
    for (int i = 0; i < sz; ++i)
        --board[candidate[i].first][candidate[i].second];
}

int Dfs(int y, int x, vector<vector<int>> &visited, vector<vector<int>> &board)
{
    int ret = 1;
    for (int d = 0; d < 4; ++d)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (nx < 0 || nx >= NN || ny < 0 || ny >= NN || board[ny][nx] == 0 || visited[ny][nx])
            continue;

        visited[ny][nx] = 1;
        ret += Dfs(ny, nx, visited, board);
    }
    
    return ret;
}

int GetMaxSize(vector<vector<int>> &board)
{
    vector<vector<int>> visited(NN, vector<int>(NN));
    int maxSz = 0;
    for (int i = 0; i < NN; ++i)
    {
        for (int j = 0; j < NN; ++j)
        {
            if (board[i][j] && !visited[i][j])
            {
                visited[i][j] = 1;
                maxSz = max(maxSz, Dfs(i, j, visited, board));
            }
        }
    }

    return maxSz;
}

int GetSum(vector<vector<int>> &board)
{
    int sum = 0;
    for (int i = 0; i < NN; ++i)
        for (int j = 0; j < NN; ++j)
            sum += board[i][j];

    return sum;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    NN = (1 << N);
    vector<vector<vector<int>>> board(2, vector<vector<int>>(NN, vector<int>(NN)));
    for (int i = 0; i < NN; ++i)
        for (int j = 0; j < NN; ++j)
            cin >> board[0][i][j];
    
    for (int i = 0; i < Q; ++i)
    {
        int level;
        cin >> level;
        for (int l = level; l >= 1; --l)
        {
            Rotate(N - l + 1, 0, 0, 0, NN, board);
            CopyToOriginal(board);
        }
        Melt(board[0]);
    }
    
    int sum = GetSum(board[0]);
    int maxSz = GetMaxSize(board[0]);

    cout << sum << '\n' << maxSz;

    return 0;
}