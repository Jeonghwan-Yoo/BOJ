#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> basket(N + 1);
    for (int i = 1; i <= N; ++i)
        basket[i] = i;
    int i, j;
    for (int m = 0; m < M; ++m)
    {
        cin >> i >> j;
        int tmp = basket[i];
        basket[i] = basket[j];
        basket[j] = tmp;
    }
    for (int i = 1; i <= N; ++i)
        cout << basket[i] << ' ';

    return 0;
}