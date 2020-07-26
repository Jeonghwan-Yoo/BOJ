#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    int cost[1'001];
    int cnt[1'001] = { 0, };
    for (int i = 1; i <= N; ++i)
        cin >> cost[i];
    
    int maxCnt = 0;
    int maxIdx = 0;
    int limit;
    for (int i = 0; i < M; ++i)
    {
        cin >> limit;
        for (int j = 1; j <= N; ++j)
        {
            if (cost[j] <= limit)
            {
                ++cnt[j];
                if (maxCnt < cnt[j])
                {
                    maxIdx = j;
                    maxCnt = cnt[j];
                }
                break;
            }
        }
    }
    cout << maxIdx;

    return 0;
}