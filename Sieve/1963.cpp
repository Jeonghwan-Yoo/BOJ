#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 9'999

bool sieve[MAX_N + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve[1] = true;
    for (int i = 2; i * i <= MAX_N; ++i)
        if (!sieve[i])
            for (int j = i * i; j <= MAX_N; j += i)
                sieve[j] = true;

    int T;
    cin >> T;
    while (T--)
    {
        bool visited[MAX_N + 1] = { false, };
        int from, to;
        cin >> from >> to;
        
        bool flag = false;
        queue<pair<int, int>> q;
        visited[from] = true;
        q.emplace(from, 0);
        while (!q.empty())
        {
            int cur = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (cur == to)
            {
                flag = true;
                cout << cnt << '\n';
                break;
            }
            for (int i = 1; i <= 1'000; i *= 10)
            {
                for (int j = 0; j <= 9; ++j)
                {
                    int nxt = cur / (10 * i) * (10 * i) + cur % i + i * j;
                    if (nxt >= 1'000 && !visited[nxt] && !sieve[nxt])
                    {
                        visited[nxt] = true;
                        q.emplace(nxt, cnt + 1);
                    }
                }
            }
        }
        if (!flag)
            cout << "Impossible\n";
    }
    
    return 0;
}