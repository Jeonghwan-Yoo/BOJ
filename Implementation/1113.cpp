#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int ground[50][50];
bool visited[50][50];
vector<pair<int, int > > pool;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

void flood()
{
    for (int i = 0; i < pool.size(); ++i)
    {
        ground[pool[i].second][pool[i].first] = 0;
    }
    pool.clear();
}

int pourWater(int height)
{
    int cnt = 0;
    for (int i = 0; i < pool.size(); ++i)
    {
        ground[pool[i].second][pool[i].first] = height;
        cnt ++;
    }
    pool.clear();
    return cnt;
}

bool findPool(int x, int y, int height)
{
    bool check = true;
    int curX = x;
    int curY = y;
    for (int i = 0; i < 4; ++i)
    {
        int nextX = curX + dx[i];
        int nextY = curY + dy[i];
        if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0)
        {
            check = false;
            continue;
        }
        if (visited[nextY][nextX] == true)
        {
            continue;
        }
        if (ground[nextY][nextX] == 0)
        {
            check = false;
        }
        if (ground[nextY][nextX] == height)
        {
            visited[nextY][nextX] = true;
            pool.push_back({nextX, nextY});
            if (findPool(nextX, nextY, height) == false)
                check = false;

        }
    }
    return check;
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N >> M;
    int maxHeight = 0;
    int totalWater = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            char tmp;
            cin >> tmp;
            ground[i][j] = tmp - '0';
            maxHeight = max(maxHeight, ground[i][j]);
        }
    }
    for (int height = 1; height <= maxHeight; ++height)
    {
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (ground[i][j] == height && visited[i][j] == false)
                {
                    visited[i][j] = true;
                    pool.push_back({j, i});
                    if (findPool(j, i, height) == true)
                    {
                        totalWater += pourWater(height + 1);
                    }
                    else
                    {
                        flood();
                    }
                }
            }
        }
        
    }
    cout << totalWater;

    return 0;
}