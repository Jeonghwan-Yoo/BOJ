#include <iostream>
#include <deque>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L;
    cin >> N >> L;
    deque<pair<int, int> > d;
    for (int i = 0; i < N; ++i)
    {
        int in;
        cin >> in;
        if (!d.empty() && d.front().second + L <= i)
            d.pop_front();
        while (!d.empty() && d.back().first > in)
            d.pop_back();
        d.push_back({ in, i });
        cout << d.front().first << ' ';
    }
    return 0;
}