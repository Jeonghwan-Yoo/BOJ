#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
struct Pos
{
    int x, y;
};
vector<Pos> home;
vector<Pos> chicken;
vector<Pos> pick;
int minDist = 3000;

void CalDistance()
{
    int ret = 0;
    for (int i = 0; i < home.size(); ++i)
    {
        int dist = 200;
        for (int j = 0; j < pick.size(); ++j)
        {
            dist = min(dist, abs(home[i].x - pick[j].x) + abs(home[i].y - pick[j].y));
        }
        ret += dist;
    }
    minDist = min(ret, minDist);
}
void Dfs(int idx)
{
    if (idx > chicken.size())
    {
        return;
    }
    else if (pick.size() >= M)
    {
        CalDistance();
        return;
    }
    Dfs(idx + 1);
    pick.push_back({ chicken[idx].x, chicken[idx].y });
    Dfs(idx + 1);
    pick.pop_back();
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int in;
            cin >> in;
            if (in == 1)
            {
                home.push_back({ j, i });
            }
            else if (in == 2)
            {
                chicken.push_back({ j, i });
            }
        }
    }
    Dfs(0);
    cout << minDist;
    
    return 0;
}