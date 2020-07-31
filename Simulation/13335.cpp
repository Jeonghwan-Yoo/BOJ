#include <iostream>
#include <queue>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, W, L;
    cin >> N >> W >> L;
    int truck[1'001];
    for (int i = 0; i < N; ++i)
        cin >> truck[i];
    
    queue<int> q;
    int time = 0;
    int bridge = 0;
    int pos = 0;
    int cnt = 0;
    while (cnt < N)
    {
        if ((int)q.size() >= W)
        {
            if (q.front() > 0)
                ++cnt;
            bridge -= q.front();
            q.pop();
        }
        if (pos < N && bridge + truck[pos] <= L)
        {
            q.emplace(truck[pos]);
            bridge += truck[pos];
            ++pos;
        }
        else
            q.emplace(0);
        ++time;
    }
    cout << time;

    return 0;
}