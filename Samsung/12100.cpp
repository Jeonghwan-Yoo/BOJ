#include <iostream>
#include <cstring>
#include <algorithm>

#define SZ 20

using namespace std;

int N;
int maxNum = 0;

void Rotate(int (*board)[SZ]) {
    int tmp[SZ][SZ] = { 0, };
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            tmp[N - 1 - j][i] = board[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        memcpy(board[i], tmp[i], sizeof(board[i]));
    }
}

void Merge(int (*board)[SZ]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j != N - 1 && board[i][j] == board[i][j + 1]) {
                board[i][j] <<= 1;
                board[i][j + 1] = 0;
            }
        }
    }
}

void Move(int (*board)[SZ]) {
    for (int i = 0; i < N; ++i) {
        int cur = -1;
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 0 && cur == -1) {
                cur = j;
            }
            else if (board[i][j] != 0 && cur != -1) {
                board[i][cur] = board[i][j];
                board[i][j] = 0;
                ++cur;
            }
        }
    }
}

void Gravity(int (*board)[SZ], int n) {
    if (n == 5) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                maxNum = max(maxNum, board[i][j]);
            }
        }
        return;
    }
    int tmp[SZ][SZ];

    for (int dir = 0; dir < 4; ++dir) {
        Rotate(board);
        for (int i = 0; i < N; ++i) {
            memcpy(tmp[i], board[i], sizeof(board[i]));
        }
        Move(board);
        Merge(board);
        Move(board);
        Gravity(board, n + 1);        
        for (int i = 0; i < N; ++i) {
            memcpy(board[i], tmp[i], sizeof(board[i]));
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int board[SZ][SZ] = { 0, };
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
        }
    }
    Gravity(board, 0);
    cout << maxNum;

    return 0;
}