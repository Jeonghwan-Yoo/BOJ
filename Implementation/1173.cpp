#include <iostream>
#include <algorithm>

using namespace std;

int N, m, M, T, R;
int minN = 40001;

void makeSchedule(int n, int nWorkOut, int nowBeat)
{
	if (nWorkOut == N)
	{
		minN = min(minN, n);
		return;
	}
	if (nowBeat + T <= M)
    {
		makeSchedule(n + 1, nWorkOut + 1, nowBeat + T);
    }
    else
    {
        if (nowBeat - R >= m)
            makeSchedule(n + 1, nWorkOut, nowBeat - R);
        else
            makeSchedule(n + 1, nWorkOut, m);
    }
}

void check()
{
	if (m + T > M)
	{
		minN = -1;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	cin >> N >> m >> M >> T >> R;
	check();
	if (minN != -1)
	    makeSchedule(0, 0, m);
	cout << minN;
	return 0;
}
