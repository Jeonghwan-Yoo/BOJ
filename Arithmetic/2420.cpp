#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, M;
    cin >> N >> M;
    cout << llabs(N - M);

    return 0;
}