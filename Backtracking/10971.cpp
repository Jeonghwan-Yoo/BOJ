#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (int)1e9

int N;
int minVal;

void Tsp(int src, int start, int cnt, int sum, vector<int> &visited, vector<vector<int>> const &board)
{
    if (cnt >= N && src == start)
    {
        minVal = min(minVal, sum);
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (visited[i] || board[src][i] == 0)
            continue;
        
        int nsum = sum + board[src][i];
        if (nsum < minVal)
        {
            visited[i] = 1;
            Tsp(i, start, cnt + 1, nsum, visited, board);
            visited[i] = 0;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    minVal = INF;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    vector<int> visited(N);
    Tsp(0, 0, 0, 0, visited, board);

    cout << minVal;

    return 0;
}