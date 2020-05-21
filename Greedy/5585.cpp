#include <iostream>

using namespace std;

#define PRICE 1000

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int change = PRICE - N;
    constexpr int coin[6] = { 500, 100, 50, 10, 5, 1 };
    int totalCnt = 0;
    for (int i = 0; i < 6; ++i)
    {
        int cnt = change / coin[i];
        totalCnt += cnt;
        change -= cnt * coin[i];
        if (change == 0)
            break;
    }
    cout << totalCnt;

    return 0;
}