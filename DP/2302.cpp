#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 1;
    int N, M;
    cin >> N >> M;
    vector<int> fibo(N + 1);
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i <= N; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    int vip[2] = { 0, };
    for (int i = 0; i < M; ++i)
    {
        int cur = i & 1;
        int prev = (i + 1) & 1;
        cin >> vip[cur];
        num *= fibo[vip[cur] - vip[prev] - 1];
        vip[prev] = vip[cur];
    }
    num *= fibo[N + 1 - vip[0] - 1];
    cout << num;

    return 0;
}