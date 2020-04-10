#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N, M;
        cin >> N >> M;
        int comb[31][31] = { 0, };
        for (int i = 0; i < 31; ++i)
        {
            comb[i][0] = 1;
        }
        comb[1][1] = 1;
        for (int i = 2; i <= M; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            }
            
        }
        cout << comb[M][N] << '\n';
    }
    return 0;
}