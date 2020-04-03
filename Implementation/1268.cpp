#include <iostream>
#include <algorithm>

using namespace std;

int table[1000][5];
int knowing[1000];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            cin >> table[i][j];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                if (table[i][k] == table[j][k])
                {
                    ++knowing[i];
                    ++knowing[j];
                    break;
                }
            }
        }
    }
    int captain = 0;
    int num = 0;
    for (int i = 0; i < N; ++i)
    {
        if (num > knowing[i])
        {
            captain = i;
            num = knowing[i];
        }
    }
    cout << captain + 1;

    return 0;
}