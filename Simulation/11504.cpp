#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, N, M;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        long long x = 0;
        long long y = 0;
        int in;
        int spin[201];
        for (int i = 0; i < M; ++i)
        {
            cin >> in;
            x += in;
            x *= 10;
        }
        for (int i = 0; i < M; ++i)
        {
            cin >> in;
            y += in;
            y *= 10;
        }
        for (int i = 0; i < N; ++i)
            cin >> spin[i];
        for (int i = N; i < (N << 1); ++i)
            spin[i] = spin[i - N];
        
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            long long tmp = 0;
            for (int j = 0; j < M; ++j)
            {
                tmp += spin[i + j];
                tmp *= 10;
            }
            if (x <= tmp && tmp <= y)
                ++cnt;
        }
        cout << cnt << '\n';
    }

    return 0;
}