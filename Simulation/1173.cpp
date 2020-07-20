#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;
    
    int time = 0;
    int workout = 0;
    int beat = m;
    if (beat + T > M)
        time = -1;
    else
    {
        while (workout < N)
        {
            ++time;
            if (beat + T <= M)
            {
                ++workout;
                beat += T;
            }
            else
            {
                beat -= R;
                if (beat < m)
                    beat = m;
            }
        }
    }    
    cout << time;

    return 0;
}