#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

#define END 32

array<array<int, 6>, 33> constexpr NEXT_POS = {{
    { 0, 1, 2, 3, 4, 5 },
    { 1, 2, 3, 4, 5, 6 },
    { 2, 3, 4, 5, 6, 7 },
    { 3, 4, 5, 6, 7, 8 },
    { 4, 5, 6, 7, 8, 9 },
    { 5, 21, 22, 23, 29, 30 },
    { 6, 7, 8, 9, 10, 11 },
    { 7, 8, 9, 10, 11, 12 },
    { 8, 9, 10, 11, 12, 13 },
    { 9, 10, 11, 12, 13, 14 },
    { 10, 24, 25, 29, 30, 31 },
    { 11, 12, 13, 14, 15, 16 },
    { 12, 13, 14, 15, 16, 17 },
    { 13, 14, 15, 16, 17, 18 },
    { 14, 15, 16, 17, 18, 19 },
    { 15, 26, 27, 28, 29, 30 },
    { 16, 17, 18, 19, 20, END },
    { 17, 18, 19, 20, END, END },
    { 18, 19, 20, END, END, END },
    { 19, 20, END, END, END, END },
    { 20, END, END, END, END, END },
    { 21, 22, 23, 29, 30, 31 },
    { 22, 23, 29, 30, 31, 20 },
    { 23, 29, 30, 31, 20, END },
    { 24, 25, 29, 30, 31, 20 },
    { 25, 29, 30, 31, 20, END },
    { 26, 27, 28, 29, 30, 31 },
    { 27, 28, 29, 30, 31, 20 },
    { 28, 29, 30, 31, 20, END },
    { 29, 30, 31, 20, END, END },
    { 30, 31, 20, END, END, END },
    { 31, 20, END, END, END, END },
    { END, END, END, END, END, END },
}};
array<int, 33> constexpr SCORE = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13, 16, 19, 22, 24, 28, 27, 26, 25, 30, 35, 0 };

struct Piece
{
    int pos;
    int score;
    Piece() : pos(0), score(0) {}
};

void Backtracking(int idx, array<Piece, 4> &piece, array<int, 10> const &arr, int &maxScore, array<int, 33> &visited)
{
    if (idx == (int)arr.size())
    {
        int sum = 0;
        for (int i = 0; i < 4; ++i)
            sum += piece[i].score;
        maxScore = max(maxScore, sum);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        if (piece[i].pos == END)
            continue;

        Piece prev = piece[i];
        int npos = NEXT_POS[piece[i].pos][arr[idx]];
        if (npos == END || visited[npos] == false)
        {
            visited[piece[i].pos] = false;
            piece[i].pos = npos;
            piece[i].score += SCORE[npos];
            visited[piece[i].pos] = true;
            Backtracking(idx + 1, piece, arr, maxScore, visited);
            visited[piece[i].pos] = false;
            piece[i] = prev;
            visited[piece[i].pos] = true;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<int, 10> arr;
    for (int i = 0; i < 10; ++i)
        cin >> arr[i];

    int maxScore = 0;
    array<Piece, 4> piece;
    array<int, 33> visited = { false, };
    Backtracking(0, piece, arr, maxScore, visited);
    cout << maxScore;
 
    return 0;
}