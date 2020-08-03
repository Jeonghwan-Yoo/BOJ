#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int biggest = (int)log2(N) + 1;
    int num = N;
    int shop = 0;
    while (1)
    {
        int cnt = 0;
        for (int i = (1 << biggest); i > 0; i >>= 1)
            if (num & i)
                ++cnt;

        if (cnt <= K)
            break;
        
        int minimum = num & (-num);
        shop += minimum;
        num += minimum;
    }
    cout << shop;

    return 0;
}