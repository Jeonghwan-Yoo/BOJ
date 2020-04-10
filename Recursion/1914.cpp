#include <iostream>
#include <string>

using namespace std;

void Hanoi(int from, int mid, int to, int n)
{
    if (n == 1)
    {
        cout << from << ' ' << to << '\n';
        return;
    }
    Hanoi(from, to, mid, n - 1);
    Hanoi(from, mid, to, 1);
    Hanoi(mid, from, to, n - 1);
}

string ToString(__int128 val)
{
    string s;
    while (val)
    {
        int tmp = val % 10;
        s = to_string(tmp) + s;
        val /= 10;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    __int128 cnt = 1;
    for (int i = 0; i < N - 1; ++i)
    {
        cnt = (cnt << 1) + 1;
    }
    cout << ToString(cnt) << '\n';
    if (N <= 20)
        Hanoi(1, 2, 3, N);
    
    return 0;
}