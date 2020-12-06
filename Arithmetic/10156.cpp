#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K, N, M;
    cin >> K >> N >> M;
    int lack = K * N - M;
    if (lack < 0)
        cout << 0;
    else
        cout << lack;

    return 0;
}