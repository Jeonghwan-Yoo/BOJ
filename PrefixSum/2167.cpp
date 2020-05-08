#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    int arr[301][301] = { 0, };
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];
    
    int prefix[301 + 1][301 + 1] = { 0, };
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i - 1][j - 1];
    int K;
    cin >> K;
    for (int k = 0; k < K; ++k)
    {
        int i, j, x, y;
        cin >> i >> j >> x >> y;
        cout << prefix[x][y] - prefix[x][j - 1] - prefix[i - 1][y] + prefix[i - 1][j - 1] << '\n';
    }

    return 0;
}