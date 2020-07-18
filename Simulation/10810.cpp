#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int basket[101] = { 0, };
    int N, M;
    cin >> N >> M;
    int i, j, k;
    for (int m = 0; m < M; ++m)
    {
        cin >> i >> j >> k;
        for (int start = i; start <= j; ++start)
            basket[start] = k;
    }
    for (int n = 1; n <= N; ++n)
        cout << basket[n] << ' ';

    return 0;
}