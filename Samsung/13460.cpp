#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

char board[11][11];
queue<tuple<int, int, int> > qR;
queue<tuple<int, int, int> > qB;
pair<int, int> O;
bool visited[11][11][11][11];

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int bfs() {
    while (!qR.empty() && !qB.empty()) {    
        int n = get<0>(qR.front());
        if (n > 10) {
            return -1;
        }
        int rx = get<1>(qR.front());
        int ry = get<2>(qR.front());
        int bx = get<1>(qB.front());
        int by = get<2>(qB.front());
        qR.pop();
        qB.pop();
        for (int i = 0; i < 4; ++i) {
            int nextRx = rx + dx[i];
            int nextRy = ry + dy[i];
            int nextBx = bx + dx[i];
            int nextBy = by + dy[i];
            bool overlapped = false;
            if (visited[nextRy][nextRx][nextBy][nextBx] == true) {
                continue;
            }        
            while ((board[nextBy][nextBx] != '#') && ((nextBy != ry) || (nextBx != rx)) && ((nextBy != O.second) || (nextBx != O.first))) {
                nextBy += dy[i];
                nextBx += dx[i];
            }
            if (nextBy == O.second && nextBx == O.first) {
                continue;
            }
            else if (nextBy == ry && nextBx == rx) {
                overlapped = true;
            }
            nextBy -= dy[i];
            nextBx -= dx[i];
            while ((board[nextRy][nextRx] != '#') && ((nextRy != nextBy) || (nextRx != nextBx)) && ((nextRy != O.second) || (nextRx != O.first))) {
                nextRy += dy[i];
                nextRx += dx[i];
            }
            if (overlapped == true) {            
                nextBy += dy[i];
                nextBx += dx[i];

                while (board[nextBy][nextBx] != '#' && ((nextBx != nextRx) || (nextBy != nextRy))) {
                    nextBy += dy[i];
                    nextBx += dx[i];
                }
                if (nextBy == O.second && nextBx == O.first) {
                    continue;
                }
                nextBy -= dy[i];
                nextBx -= dx[i]; 
                nextBy -= dy[i];
                nextBx -= dx[i]; 
            }
            if (nextRy == O.second && nextRx == O.first) {
                return n;
            }
            nextRy -= dy[i];
            nextRx -= dx[i];
            if (!visited[nextRy][nextRx][nextBy][nextBx]) {
                cout << nextRx << ' ' << nextRy << ' ' << nextBx << ' ' << nextBy << '\n';
                qR.push(make_tuple(n + 1, nextRx, nextRy)); 
                qB.push(make_tuple(n + 1, nextBx, nextBy)); 
                visited[nextRy][nextRx][nextBy][nextBx] = true;
            }
        }
    }
    return -1;
}

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char tmp;
            cin >> tmp;
            board[i][j] = tmp;
            switch (tmp) {
                case 'R':
                qR.push(make_tuple(1, j, i));
                break;
                case 'B':
                qB.push(make_tuple(1, j, i));
                break;
                case 'O':
                O = {j, i};
                break;
                default:
                break;
            }
        }
    }
    visited[get<2>(qR.front())][get<1>(qR.front())][get<2>(qB.front())][get<1>(qB.front())] = true;
    cout << bfs();
    return 0;
}