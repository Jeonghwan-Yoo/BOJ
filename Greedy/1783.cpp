#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int cnt = 0;
    if (N == 1)
        cnt = 1;
    else if (N == 2)
        cnt = min(((M + 1) >> 1), 4);
    else if (N >= 3)
    {
        cnt = min(M, 4);
        if (M >= 7)
            cnt = (M - 6) + 4;
    }
    cout << cnt;
    
    return 0;
}