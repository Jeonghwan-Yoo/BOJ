#include <iostream>

using namespace std;

int N, M;

int board[50][50];

int cleaned = 0;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

struct Bot
{
	int x;
	int y;
	int dir;

	void move()
	{
		board[y][x] = -1;
		++cleaned;
		while (1)
		{
			bool check = false;
			for (int d = 0; d < 4; ++d)
			{
				int nextDir = (dir + 3) % 4;
				dir = nextDir;
				int nextX = x + dx[dir];
				int nextY = y + dy[dir];

				if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
					continue;

				if (board[nextY][nextX] == 0)
				{
					check = true;
					x = nextX;
					y = nextY;
					move();
					break;
				}
			}
			if (check == false)
			{
				int backX = x;
				int backY = y;
				switch (dir)
				{
				case 0:
					backY += 1;
					break;
				case 1:
					backX -= 1;
					break;
				case 2:
					backY -= 1;
					break;
				case 3:
					backX += 1;
					break;
				default:
					break;
				}
				if (board[backY][backX] == 1)
				{
					return;
				}
				x = backX;
				y = backY;
			}
		}
	}
};

Bot bot;

int main()
{
	freopen("in.txt", "r", stdin);
	cin >> N >> M;
	cin >> bot.y >> bot.x >> bot.dir;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}
	bot.move();

	cout << cleaned;

	return 0;
}
