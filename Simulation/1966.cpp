#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        list<pair<int, int> > q;
        for (int i = 0; i < N; ++i)
        {
            int pri;
            cin >> pri;
            q.push_back({ pri, i });
        }
        int cur = 1;
        list<pair<int, int> >::iterator i = q.begin();
        while (q.empty() == false)
        {
            int maxPri = (*max_element(q.begin(), q.end(), [&q](const pair<int, int> &a, const pair<int, int> &b)
            {
                return a.first < b.first;
            })).first;
            if (maxPri == i->first)
            {
                if (i->second == M)
                {
                    cout << cur << '\n';
                    break;
                }
                i = q.erase(i);
                if (i == q.end())
                    i = q.begin();
                ++cur;
            }
            else
            {
                ++i;
                if (i == q.end())
                    i = q.begin();
            }
        }
    }
    return 0;
}