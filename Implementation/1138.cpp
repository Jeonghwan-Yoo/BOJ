#include <iostream>

using namespace std;

int N;
int tall[10];
int row[10];

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> tall[i];
    }
    for (int i = 0; i < N; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < N; ++j)
        {
            if (cnt == tall[i] && row[j] == 0)
            {
                row[j] = i + 1;
                break;
            }
            if (row[j] == 0)
            {
                ++cnt;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << row[i]<< ' ';
    }
    return 0;
}