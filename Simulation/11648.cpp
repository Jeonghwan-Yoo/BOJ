#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int cnt = 0;
    while (N / 10)
    {
        ++cnt;
        int newN = 1;
        while (N)
        {
            newN *= N % 10;
            N /= 10;
        }
        N = newN;
    }
    cout << cnt;

    return 0;
}