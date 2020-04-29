#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, L;
    cin >> N >> M >> L;
    int m = 0;
    int cnt = 0;
    int cur = 0;
    int people[1001] = { 0, };
    while (1)
    {
        ++people[cur];
        if (people[cur] > m)
            m = people[cur];
        if (m >= M)
            break;
        ++cnt;
        if (people[cur] & 1 == 0)
            cur = (cur - L + N) % N;
        else
            cur = (cur + L) % N;
    }
    cout << cnt;

    return 0;
}