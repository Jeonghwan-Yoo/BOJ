#include <iostream>

using namespace std;

int Combination(int n, int r, int end, int val)
{
    if (r == end)
        return val;
    int nn = n + 1;
    int nr = r + 1;
    return Combination(nn, nr, end, val * nn / nr);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    if (K != 0)
        --K;
    int r = K / M;
    int c = K % M;
    cout << Combination(r, 0, c, 1) * Combination(N - 1 - r, 0, M - 1 - c, 1);

    return 0;
}