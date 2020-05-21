#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int coin[11] = { 0, };
    int N, K;
    cin >> N >> K;
    for (int i = N - 1; i >= 0; --i)
        cin >> coin[i];
    
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        int cnt = K / coin[i];
        sum += cnt;
        K -= coin[i] * cnt;
        if (K == 0)
            break;
    }
    cout << sum;
    
    return 0;
}