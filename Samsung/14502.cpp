#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, M;
int lab[8][8];
int maxSafe = 0;
int copyLab[8][8];

const int dx[4] = { 0, 1, 0 ,-1 };
const int dy[4] = { -1, 0, 1, 0 };

struct Virus
{
	int x;
	int y;
	void extension(int r, int c)
	{
		for (int dir = 0; dir < 4; ++dir)
		{
			int nextX = c + dx[dir];
			int nextY = r + dy[dir];
			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
				continue;
			if (lab[nextY][nextX] == 0)
			{
				lab[nextY][nextX] = 2;
				extension(nextY, nextX);
			}
		}
	}
};

vector<Virus> virus;

void checkSafeZone()
{
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (lab[i][j] == 0)
				++sum;
		}
	}
	maxSafe = max(maxSafe, sum);
}

void makeWall(int r, int c, int n)
{
	if (n == 0)
	{
		memcpy(copyLab, lab, sizeof(lab));
		for (int i = 0; i < virus.size(); ++i)
		{
			virus[i].extension(virus[i].y, virus[i].x);
		}
		checkSafeZone();
		memcpy(lab, copyLab, sizeof(lab));
		return;
	}
	for (int i = r; i < N; ++i)
	{
		int j = c;
		if (i != r)
		{
			j = 0;
		}
		for (j; j < M; ++j)
		{
			if (lab[i][j] == 0)
			{
				lab[i][j] = 1;
				makeWall(i, j, n - 1);
				lab[i][j] = 0;
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> lab[i][j];
			if (lab[i][j] == 2)
			{
				Virus tmp;
				tmp.x = j;
				tmp.y = i;
				virus.push_back(tmp);
			}
		}
	}
	makeWall(0, 0, 3);
	cout << maxSafe;

	return 0;
}