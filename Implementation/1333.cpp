#include <iostream>

using namespace std;

bool listening[1005000];

int main()
{
    freopen("in.txt", "r", stdin);
    int N, L, D;
    cin >> N >> L >> D;
    int pos = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < L; ++j)
        {
            listening[pos] = true;
            ++pos;
        }
        pos += 5;
    }
    int time = D;
    while (1)
    {
        if (listening[time] == false)
        {
            break;
        }
        time += D;
    }
    cout << time;
    return 0;
}