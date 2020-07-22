#include <iostream>

using namespace std;

struct TrafficLight
{
    int D, R, G;
};

TrafficLight tl[101];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, L;
    cin >> N >> L;
    tl[0].D = 0;
    for (int i = 1; i <= N; ++i)
        cin >> tl[i].D >> tl[i].R >> tl[i].G;
    
    int time = 0;
    for (int i = 1; i <= N; ++i)
    {
        int interval = tl[i].D - tl[i - 1].D;
        time += interval;
        int elasped = time % (tl[i].R + tl[i].G);
        if (elasped < tl[i].R)
            time += tl[i].R - elasped;
    }
    time += L - tl[N].D;
    cout << time;

    return 0;
}