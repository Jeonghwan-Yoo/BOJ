#include <iostream>
#include <algorithm>

using namespace std;

int board[500][500];
int N, M;
int maxNum = 0;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

bool visited[500][500];

void makeTetro(int r, int c, int n, int sum) {
    if (n > 4) {
        maxNum = max(maxNum, sum);
        return;
    }
    if (n == 1) {
        int leftX = c + dx[1];
        int leftY = r + dy[1];
        if (!visited[leftY][leftX] && leftX >= 0 && leftX < M && leftY >= 0 && leftY < N) {
            visited[leftY][leftX] = true;
            makeTetro(leftY, leftX, n + 1, sum + board[leftY][leftX]);
            visited[leftY][leftX] = false;
        }
        int downX = c + dx[2];
        int downY = r + dy[2];
        if (!visited[downY][downX] && downX >= 0 && downX < M && downY >= 0 && downY < N) {
            visited[downY][downX] = true;
            makeTetro(downY, downX, n + 1, sum + board[downY][downX]);
            visited[downY][downX] = false;
        }
    }
    else {
        if (n == 4) {
            for (int i = 0; i < 4; ++i) {
                int prevX = c - dx[i];
                int prevY = r - dy[i];
                if (prevX < 0 || prevX >= M || prevY < 0 || prevY >= N)
                    continue;
                if (visited[prevY][prevX]) {
                    for (int j = 0; j < 4; ++j) {
                        int nextX = prevX + dx[j];
                        int nextY = prevY + dy[j];
                        if (nextX < 0 || nextX >= M || nextY < 0 | nextY >= N)
                            continue;
                        if (visited[nextY][nextX])
                            continue;
                        visited[nextY][nextX] = true;
                        makeTetro(nextY, nextX, n + 1, sum + board[nextY][nextX]);
                        visited[nextY][nextX] = false;
                    }
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nextX = c + dx[i];
            int nextY = r + dy[i];
            if (nextX < 0 || nextX >= M || nextY < 0 | nextY >= N)
                continue;
            if (visited[nextY][nextX])
                continue;
            visited[nextY][nextX] = true;
            makeTetro(nextY, nextX, n + 1, sum + board[nextY][nextX]);
            visited[nextY][nextX] = false;
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            makeTetro(i, j, 1, 0);
        }
    }
    cout << maxNum;
    return 0;
}