#include <iostream>
#include <map>

using namespace std;

map<long long, pair<int, int> > lamp;
int N, M;
int K;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        long long num = 0;
        int cnt = 0;
        for (int j = 0; j < M; ++j)
        {
            char in;
            cin >> in;
            num += (1ll << j) * (in - '0');
            cnt += (in - '0') ^ 1;
        }
        if (lamp.count(num) != 0)
        {
            lamp[num].second += 1;
            continue;
        }
        lamp[num].first = cnt;
        lamp[num].second = 1;
    }
    cin >> K;
    int maxOn = 0;
    for (auto& i : lamp)
    {
        if (i.second.first <= K && ((K - i.second.first) & 1) == 0)
        {
            if (i.second.second > maxOn)
            {
                maxOn = i.second.second;
            }
        }
    }
    cout << maxOn;

    return 0;
}