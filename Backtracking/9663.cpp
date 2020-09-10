#include <iostream>

using namespace std;

int N;
bool visited[3][31];
int cnt;

void Backtracking(int r)
{
    if (r == N)
    {
        ++cnt;
        return;
    }
    for (int c = 0; c < N; ++c)
    {
        if (visited[0][c] + visited[1][r + c] + visited[2][N - (r - c)] == 0)
        {
            visited[0][c] = visited[1][r + c] = visited[2][N - (r - c)] = 1;
            Backtracking(r + 1);
            visited[0][c] = visited[1][r + c] = visited[2][N - (r - c)] = 0;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    Backtracking(0);
    cout << cnt;

    return 0;
}