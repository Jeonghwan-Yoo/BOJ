#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int numOfKnowing;
int knowing[51];
bool fail[51];
vector<int> member[51];

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N >> M;
    cin >> numOfKnowing;
    int first = -1;
    for (int i = 0; i < numOfKnowing; ++i)
    {
        int tmp;
        cin >> tmp;
        knowing[tmp] = 1;
        if (i == 0)
            first = tmp;
    }
    int ppl = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> ppl;
        for (int j = 0; j < ppl; ++j)
        {
            int tmp;
            cin >> tmp;
            member[i + 1].push_back(tmp);
        }
    }
    while (1)
    {
        bool finished = true;
        for (int i = 1; i <= M; ++i)
        {
            if (fail[i] == true)
                continue;
            for (int j = 0; j < member[i].size(); ++j)
            {
                for (int k = 1; k <= N; ++k)
                {
                    if (knowing[member[i][j]] == true)
                    {
                        for (int l = 0; l < member[i].size(); ++l)
                        {
                            knowing[member[i][l]] = true;
                        }
                        fail[i] = true;
                        finished = false;
                    }

                }
            }
        }
        if (finished == true)
            break;
    }

    int cnt = 0;
    for (int i = 1; i <= M; ++i)
    {
        if (fail[i] == false)
        {
            ++cnt;
        }
    }
    cout << cnt;

    return 0;
}