#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Ground
{
    vector<pair<int, int> > tree;
    int nutrient;
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Ground ground[11][11];
    int A[11][11];
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> A[i][j];
            ground[i][j].nutrient = 5;
        }
    }
    for (int i = 0; i < M; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        ground[x][y].tree.push_back({ z, 1 });
    }
    while (K--)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                Ground &g = ground[i][j];
                int extinct = 0;
                int deathNutrient = 0;
                sort(g.tree.begin(), g.tree.end());
                for (int t = 0; t < (int)g.tree.size(); ++t)
                {
                    int y = g.tree[t].first;
                    int c = g.tree[t].second;
                    if (g.nutrient >= y * c)
                    {
                        g.nutrient -= y * c;
                        ++g.tree[t].first;
                    }
                    else
                    {
                        int leftover = g.nutrient / y;
                        if (leftover == 0)
                        {
                            ++extinct;
                            deathNutrient += (y >> 1) * c;
                        }
                        else
                        {
                            deathNutrient += (y >> 1) * (c - leftover);
                            g.nutrient -= y * leftover;
                            ++g.tree[t].first;
                            g.tree[t].second = leftover;
                        }
                    }
                }
                g.nutrient += deathNutrient;
                while (extinct--)
                    g.tree.pop_back();
            }
        }
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                Ground &g = ground[i][j];
                for (int t = 0; t < (int)g.tree.size(); ++t)
                {
                    if ((g.tree[t].first % 5) == 0)
                    {
                        for (int dir = 0; dir < 8; ++dir)
                        {
                            int nr = i + dr[dir];
                            int nc = j + dc[dir];
                            if (nr < 1 || nr > N || nc < 1 || nc > N)
                                continue;
                            if (ground[nr][nc].tree.empty() == false && ground[nr][nc].tree.back().first == 1)
                                ground[nr][nc].tree.back().second += g.tree[t].second;
                            else
                                ground[nr][nc].tree.push_back({ 1, g.tree[t].second });
                        }
                    }
                }
                g.nutrient += A[i][j];
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            for (int t = 0; t < (int)ground[i][j].tree.size(); ++t)
                cnt += ground[i][j].tree[t].second;

    cout << cnt;

    return 0;
}