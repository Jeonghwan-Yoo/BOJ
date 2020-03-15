#include <iostream>

using namespace std;

int N, M, X, Y, K;

int board[20][20];
int cmd[1000];

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

enum Dir {
    None = 0,
    East,
    West,
    North,
    South,
};

struct Dice {
    int x = 0;
    int y = 0;
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
    int forth = 0;
    int back = 0;

    void copyBoard() {
        if (y >= 0 && y < N && x >= 0 && x < M) {
            if (board[y][x] == 0) {
                board[y][x] = down;
            }
            else {
                down = board[y][x];
                board[y][x] = 0;
            }
        }
    }
    
    void move(Dir dir) {
        x += dx[dir - 1];
        y += dy[dir - 1];
        switch (dir) {
            case Dir::East: {        
                int tmp = right;
                right = up;
                up = left;
                left = down;
                down = tmp;
                break;
            }
            case Dir::West: {
                int tmp = left;
                left = up;
                up = right;
                right = down;
                down = tmp;
                break;

            }
            case Dir::North: {
                int tmp = back;
                back = up;
                up = forth;
                forth = down;
                down = tmp;
                break;

            }
            case Dir::South: {
                int tmp = forth;
                forth = up;
                up = back;
                back = down;
                down = tmp;
                break;

            }
            default: {
                break;
            }
        }
    }
    void printUp() {
        cout << up << '\n';
    }
};


int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> X >> Y >> K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int tmp;
            cin >> tmp;
            board[i][j] = tmp;
        }
    }
    for (int i = 0; i < K; ++i) {
        cin >> cmd[i];
    }
    Dice dice;
    dice.x = Y;
    dice.y = X;
    for (int i = 0; i < K; ++i) {
        int nextX = dice.x + dx[cmd[i] - 1];
        int nextY = dice.y + dy[cmd[i] - 1];
        if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
            continue;

        dice.move(static_cast<Dir>(cmd[i]));
        dice.copyBoard();
        dice.printUp();
    }
    return 0;
}