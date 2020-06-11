#include <iostream>

using namespace std;

int N;
int adj[21][21];
int time[21][21];

bool InverseFloyd()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            adj[i][j] = time[i][j];

    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (i == k || k == j)
                    continue;
                if (time[i][k] + time[k][j] == time[i][j])
                    adj[i][j] = 0;
                else if (time[i][k] + time[k][j] < time[i][j])
                {
                    adj[i][j] = -1;
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> time[i][j];
    
    bool ret = InverseFloyd();
    if (ret == false)
        cout << -1;
    else
    {
        int sum = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                sum += adj[i][j];
        cout << sum;
    }

    return 0;
}