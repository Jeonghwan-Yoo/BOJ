#include <iostream>

using namespace std;

int constexpr dx[4] = { 0, 1, 0, -1 };
int constexpr dy[4] = { -1, 0, 1, 0 };

int N, M, T;
int circle[51][51];
bool visited[51][51];

void Rotate(int idx, int dir, int cnt)
{
    if (dir == 0)
        cnt = M - cnt;
    int tmp[51];
    for (int i = idx; i <= N; i += idx)
    {
        for (int j = 0; j < M; ++j)
            tmp[j] = circle[i][j];

        for (int j = 0; j < M; ++j)
            circle[i][j] = tmp[(j + cnt) % M];
    }
}

int Delete(int x, int y, int val)
{
    int ret = 0;
    for (int dir = 0; dir < 4; ++dir)
    {
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
        if (nextX < 0 || nextX >= M)
            nextX = (nextX + M) % M;
        if (nextY <= 0 || nextY > N || circle[nextY][nextX] == 0)
            continue;
        if (visited[nextY][nextX] == false && circle[nextY][nextX] == val)
        {
            visited[nextY][nextX] = true;
            ret += Delete(nextX, nextY, val) + 1;
            circle[nextY][nextX] = 0;
        }
    }
    return ret;
}

void FindAdjacent()
{
    int sum = 0;
    int cnt = 0;
    bool find = false;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (circle[i][j] == 0)
                continue;

            sum += circle[i][j];
            ++cnt;
            int x = j;
            int y = i;
            for (int dir = 0; dir < 4; ++dir)
            {
                int adjX = x + dx[dir];
                int adjY = y + dy[dir];
                if (adjX < 0 || adjX >= M)
                    adjX = (adjX + M) % M;
                if (adjY <= 0 || adjY > N || circle[adjY][adjX] == 0)
                    continue;
                if (circle[y][x] == circle[adjY][adjX])
                {
                    find = true;
                    break;
                }
            }
            if (find == true)
                break;
        }
        if (find ==  true)
            break;
    }

    if (find == true)
    {
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                visited[i][j] = false;

        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (visited[i][j] == false || circle[i][j] == 0)
                {
                    visited[i][j] = true;
                    if (Delete(j, i, circle[i][j]) > 0)
                        circle[i][j] = 0;
                }
            }
        }
    }
    else
    {
        double avg = (double)sum / cnt;
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (circle[i][j] == 0)
                    continue;
                if ((double)circle[i][j] > avg)
                    --circle[i][j];
                else if ((double)circle[i][j] < avg)
                    ++circle[i][j];
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> circle[i][j];
    
    int x, d, k;
    for (int i = 0; i < T; ++i)
    {
        cin >> x >> d >> k;
        Rotate(x, d, k);   
        FindAdjacent();
    }

    int sum = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
            sum += circle[i][j];
    cout << sum;

    return 0;
}