#include <iostream>
#include <queue>

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
        queue<pair<int, int> > q;
        priority_queue<int> pq;
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
        {
            int in;
            cin >> in;
            pq.push(in);
            q.push({ i, in });
        }
        int cnt = 0;
        while (!q.empty())
        {
            pair<int, int> tmp = q.front();
            if (pq.top() != tmp.second)
            {
                q.pop();
                q.push(tmp);
            }
            else
            {
                ++cnt;
                if (tmp.first == M)
                    break;
                pq.pop();
                q.pop();
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}