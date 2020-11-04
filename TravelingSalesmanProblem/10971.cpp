#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (int)1e9

int N;

int Tsp(int src, int visited, vector<vector<int>> &dp, vector<vector<int>> const &board)
{
    if (visited == (1 << N) - 1)
    {
        if (board[src][0] == 0)
            return INF;
        return board[src][0];
    }

    int &cur = dp[visited][src];
    if (cur > 0)
        return cur;

    cur = INF;
    for (int i = 0; i < N; ++i)
    {
        if ((visited & (1 << i)) || board[src][i] == 0)
            continue;
        
        cur = min(cur, Tsp(i, visited | (1 << i), dp, board) + board[src][i]);
    }

    return cur;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    vector<vector<int>> dp(1 << N, vector<int>(N));    
    cout << Tsp(0, 1, dp, board);

    return 0;
}