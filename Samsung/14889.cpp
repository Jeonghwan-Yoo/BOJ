#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int synergy[20][20];
int minDiff = 987654321;
int team[20];

void makeTeam(int next, int left)
{
    if (left == 0)
    {
        int sumStart = 0;
        int sumLink = 0;
        vector<int> start;
        vector<int> link;
        for (int i = 0; i < N; ++i)
        {
            if (team[i] == 0)
                start.push_back(i);
            else
                link.push_back(i);
        }
        for (int i = 0; i < start.size(); ++i)
        {
            for (int j = 0; j < start.size(); ++j)
            {
                if (i != j)
                    sumStart += synergy[start[i]][start[j]];
            }
        }
        
        for (int i = 0; i < link.size(); ++i)
        {
            for (int j = 0; j < link.size(); ++j)
            {
                if (i != j)
                    sumLink += synergy[link[i]][link[j]];
            }
        }
        minDiff = min(minDiff, abs(sumStart - sumLink));
    }
    for (int i = next; i < N; ++i)
    {
        if (team[i] == 0)
        {
            team[i] = 1;
            makeTeam(i + 1, left - 1);
            team[i] = 0;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> synergy[i][j];
        }
    }
    makeTeam(0, N >> 1);
    cout << minDiff;

    return 0;
}