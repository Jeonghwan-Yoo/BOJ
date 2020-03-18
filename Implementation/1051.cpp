#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    int board[50][50] = { 0, };
    for (int i = 0; i < N; ++i) {
        char tmp;
        for (int j = 0; j < M; ++j) {
            cin >> tmp;
            board[i][j] = tmp - '0';
        }
    }
    int minVal = min(N, M);
    int maxArea = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 1; k < minVal; ++k) {
                if (i + k >= N || j + k >= M)
                    break;
                if (board[i][j] ==  board[i + k][j] && board[i + k][j] == board[i][j + k] && board[i][j + k] == board[i + k][j + k] && board[i + k][j + k] == board[i][j]) {
                    maxArea = max(maxArea, (k + 1) * (k + 1));
                }
            }
        }
    }
    cout << maxArea;

    return 0;
}