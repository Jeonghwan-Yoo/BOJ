#include <iostream>
#include <array>
#include <unordered_set>
#include <string>

using namespace std;

#define SZ 5

array<int, 4> constexpr dx = { 0, 1, 0, -1 };
array<int, 4> constexpr dy = { -1, 0, 1, 0 };

void Dfs(int x, int y, string &s, array<array<string, 5>, 5> const &board, unordered_set<string> &setNumber)
{
    if ((int)s.size() >= SZ + 1)
    {
        setNumber.insert(s);
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= SZ || ny < 0 || ny >= SZ)
            continue;
        
        s += board[ny][nx];
        Dfs(nx, ny, s, board, setNumber);
        s.pop_back();
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<string> setNumber;
    array<array<string, SZ>, SZ> board;
    for (int i = 0; i < SZ; ++i)
        for (int j = 0; j < SZ; ++j)
            cin >> board[i][j];

    for (int i = 0; i < SZ; ++i)
    {
        for (int j = 0; j < SZ; ++j)
        {
            string s;
            s += board[i][j];
            Dfs(j, i, s, board, setNumber);
        }
    }
    cout << (int)setNumber.size();

    return 0;
}