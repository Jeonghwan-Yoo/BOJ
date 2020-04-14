#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> cache;

void MakeCache(int n)
{
    vector<string> tmp;
    for (int i = 1; i < 10; ++i)
    {
        for (int j = 0; j < cache.size(); ++j)
        {
            if (cache[j].size() == n && cache[j][0] - '0' < i)
            {
                string str = to_string(i) + cache[j];
                tmp.push_back(str);
            }
        }
    }
    for (int i = 0; i < tmp.size(); ++i)
    {
        cache.push_back(tmp[i]);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    for (int i = 0; i < 10; ++i)
    {
        cache.push_back(to_string(i));
    }
    for (int i = 1; i < 10; ++i)
    {
        MakeCache(i);
    }
    if (N >= cache.size())
    {
        cout << -1;
    }
    else
    {
        cout << cache[N];
    }

    return 0;
}
