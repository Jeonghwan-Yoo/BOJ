#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int constexpr dr[4] = { 0, 0, -1, 1 };
int constexpr dc[4] = { 1, -1, 0, 0 };

enum Color
{
    White = 0,
    Red = 1,
    Blue = 2,
};

struct Piece
{
    int r, c, d;
    Piece(int r, int c, int d) : r(r), c(c), d(d) {}
};

int N, K;
pair<int, vector<int> > board[13][13];
vector<Piece> piece;

bool Turn()
{
    for (int i = 0; i < (int)piece.size(); ++i)
    {
        int curR = piece[i].r;
        int curC = piece[i].c;
        int curD = piece[i].d;
        int nextR = curR + dr[curD];
        int nextC = curC + dc[curD];
        if (nextR <= 0 || nextR > N || nextC <= 0 || nextC > N || board[nextR][nextC].first == Color::Blue)
        {
            if (curD == 0 || curD == 2)
                ++curD;
            else
                --curD;
            nextR = curR + dr[curD];
            nextC = curC + dc[curD];
            piece[i].d = curD;
            if (nextR <= 0 || nextR > N || nextC <= 0 || nextC > N || board[nextR][nextC].first == Color::Blue)
                continue;
        }

        vector<int> group;
        int pos = -1;
        for (int j = 0; j < (int)board[curR][curC].second.size(); ++j)
        {
            if (board[curR][curC].second[j] == i)
            {
                pos = j;            
                break;
            }
        }
        for (int j = pos; j < (int)board[curR][curC].second.size(); ++j)
            group.emplace_back(board[curR][curC].second[j]);
        
        if ((int)group.size() + (int)board[nextR][nextC].second.size() >= 4)
            return true;

        if (board[nextR][nextC].first == Color::Red)
            reverse(group.begin(), group.end());

        for (int j = 0; j < (int)group.size(); ++j)
        {
            piece[group[j]].r = nextR;
            piece[group[j]].c = nextC;
        }

        for (int j = 0; j < (int)group.size(); ++j)
            board[curR][curC].second.pop_back();
        for (int j = 0; j < (int)group.size(); ++j)
            board[nextR][nextC].second.emplace_back(group[j]);
    }
    return false;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j].first;
    
    int r, c, d;
    for (int i = 0; i < K; ++i)
    {
        cin >> r >> c >> d;
        piece.emplace_back(r, c, d - 1);
        board[r][c].second.emplace_back(i);
    }
    
    int time = 0;
    bool finished = false;
    while (time <= 1000)
    {
        ++time;
        finished = Turn();
        if (finished == true)
            break;
    }
    if (finished == false)
        time = -1;
    cout << time;

    return 0;
}