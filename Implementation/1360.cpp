#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    string res;
    map<int, string> cache;
    for (int i = 0; i < N; ++i)
    {
        string type;
        cin >> type;
        if (type[0] == 't')
        {
            char c;
            int time;
            cin >> c >> time;
            res += c;
            cache[time] = res;
        }
        else if (type[0] == 'u')
        {
            int t;
            int time;
            cin >> t >> time;
            int prev = time - t - 1;
            if (prev < 0)
            {
                prev = 0;
            }
            int pos = 0;
            for (auto& j : cache)
            {
                if (j.first <= prev)
                {
                    pos = j.first;
                }
            }
            res = cache[pos];
            cache[time] = res;
        }
    }
    cout << res;
    return 0;
}