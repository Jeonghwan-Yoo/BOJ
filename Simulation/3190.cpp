#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum State {
    StateNone = 0,
    Grow = 1,
};

enum Dir {
    Up = 0,
    Right = 1,
    Down = 2,
    Left = 3,
};

struct Snake {
    Dir dir = Dir::Right;
    vector<pair<int, int> > body;
    State state = State::StateNone;
};

int N, K, L;

int board[100][100];

queue<pair<int, char> > moveSnake;

int time = 0;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

void start(Snake& snake) {
    while (1) {
        ++time;
        pair<int, int> prevHead = snake.body[0];
        snake.body[0].first += dx[snake.dir];
        snake.body[0].second += dy[snake.dir];
        if (snake.body[0].first < 0 || snake.body[0].first >= N || snake.body[0].second < 0 || snake.body[0].second >= N) {
            return;
        }
        for (int i = 1; i < snake.body.size(); ++i) {
            if (snake.body[0].first == snake.body[i].first && snake.body[0].second == snake.body[i].second) {
                return;
            }
        }
        if (board[snake.body[0].second][snake.body[0].first] == 1) {
            snake.state = State::Grow;            
            board[snake.body[0].second][snake.body[0].first] = 0;
        }
        pair<int, int> lastBody;
        pair<int, int> tmp = prevHead;
        for (int i = 1; i < snake.body.size(); ++i) {
            pair<int, int> tmp2 = snake.body[i];
            snake.body[i] = tmp;
            tmp = tmp2;
        }
        lastBody = tmp;
        if (snake.state == State::Grow) {
            snake.body.push_back(make_pair(lastBody.first, lastBody.second));
            snake.state = State::StateNone;
        }
        if (!moveSnake.empty()) {
            if (time == moveSnake.front().first) {
                switch (moveSnake.front().second) {
                    case 'L': {
                        int tmp = (int)snake.dir;
                        snake.dir = static_cast<Dir>((tmp - 1) % 4);
                        if (tmp == 0)
                            snake.dir = Dir::Left;
                        break;
                    }
                    case 'D': {
                        int tmp = (int)snake.dir;
                        snake.dir = static_cast<Dir>((tmp + 1) % 4);
                        break;
                    }
                    default: {
                        break;
                    }
                }
                moveSnake.pop();
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> N;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        board[r - 1][c - 1] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; ++i) {
        int t;
        char dir;
        cin >> t >> dir;
        moveSnake.push(make_pair(t, dir)); 
    }
    Snake snake;
    snake.body.push_back({ 0, 0 });
    start(snake);
    cout << time;

    return 0;
}