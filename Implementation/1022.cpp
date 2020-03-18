#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int r1, c1, r2, c2;

int GetValue(int r, int c) {
    int bigger = max(abs(r), abs(c));
    int last = ((bigger << 1) + 1) * ((bigger << 1) + 1);
    int ret = 0;
    if (r == bigger) {
        ret = last - (bigger - c);
    }
    else if (c == -bigger) {
        ret = last - (bigger << 1) - (bigger - r);
    }
    else if (r == -bigger) {
        ret = last - (bigger << 2) - (bigger + c);
    }
    else if (c == bigger) {
        ret = last - ((bigger << 2) + (bigger << 1)) - (bigger + r);
    }
    return ret;
}

int main() {
    cin >> r1 >> c1 >> r2 >> c2;
    int maxNum = 0;
    int board[50][5];
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) {
            board[i - r1][j - c1] = GetValue(i, j);
            maxNum = max(maxNum, board[i - r1][j - c1]);
        }
    }

    int maxFigure = 0;
    while (maxNum) {
        ++maxFigure;
        maxNum /= 10;
    }
    for (int i = 0; i <= r2 - r1; ++i) {
        for (int j = 0; j <= c2 - c1; ++j) {
            cout << setw(maxFigure) << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}