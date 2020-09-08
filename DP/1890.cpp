#include <iostream>
#include <cstring>

using namespace std;

int N;
int board[101][101];
long long dp[101][101];

long long Dfs(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= N)
        return 0ll;


    if (x == N - 1 && y == N - 1)
        return 1ll;

    long long &ret = dp[y][x];
    if (ret != -1ll)
        return ret;
    
    ret = 0ll;
    ret += Dfs(x + board[y][x], y);
    ret += Dfs(x, y + board[y][x]);
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    
    memset(dp, -1, sizeof(dp));
    
    cout << Dfs(0, 0);

    return 0;
}