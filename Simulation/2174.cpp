#include <iostream>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

int A, B, N, M;
int board[101][101];
bool collision = false;

struct Robot
{
    int _x, _y, _d;
    void Init(int x, int y, char d)
    {
        _x = x;
        _y = y;
        if (d == 'N')
            _d = 0;
        else if (d == 'E')
            _d = 1;
        else if (d == 'S')
            _d = 2;
        else if (d == 'W')
            _d = 3;
    }
    
    void Move()
    {
        int nextX = _x + dx[_d];
        int nextY = _y + dy[_d];
        if (nextX <= 0 || nextX > A || nextY <= 0 || nextY > B)
        {
            cout << "Robot " << board[_y][_x] << " crashes into the wall";
            collision = true;
            return;
        }
        if (board[nextY][nextX] != 0)
        {
            cout << "Robot " << board[_y][_x] << " crashes into robot " << board[nextY][nextX];
            collision = true;
            return;
        }
        board[nextY][nextX] = board[_y][_x];
        board[_y][_x] = 0;
        _x = nextX;
        _y = nextY;
    }

    void Rotate(char command)
    {
        if (command == 'L')
            _d += 2; 
        _d = (_d + 1) & 3;
    }
    
    void Command(char command, int cnt)
    {
        for (int i = 0; i < cnt; ++i)
        {
            if (command == 'F')
                Move();
            else
                Rotate(command);

            if (collision == true)
                return;
        }
    }
};

Robot robot[101];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        int x, y;
        char d;
        cin >> x >> y >> d;
        y = B - y + 1;
        robot[i].Init(x, y, d);
        board[y][x] = i;
    }
    for (int i = 0; i < M; ++i)
    {
        int n, cnt;
        char command;
        cin >> n >> command >> cnt;
        if (collision == false)
            robot[n].Command(command, cnt);
    }
    if (collision == false)
        cout << "OK";

    return 0;
}