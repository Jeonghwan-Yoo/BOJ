#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    int basket[101];
    for (int i = 1; i <= N; ++i)
        basket[i] = i;
    int i, j;
    int tmp[101];
    for (int m = 0; m < M; ++m)
    {
        cin >> i >> j;
        for (int k = i; k <= j; ++k)
            tmp[k] = basket[k];

        for (int k = i; k <= j; ++k)
            basket[k] = tmp[i + j - k];
    }   
    for (int n = 1; n <= N; ++n)
        cout << basket[n] << ' ';

    return 0;
}