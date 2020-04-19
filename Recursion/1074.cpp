#include <iostream>

using namespace std;

int N, r, c;
int val = 0;

void FindValue(int n, int r, int c)
{
    if (n <= 0)
    {
        return;
    }
    int num = (1 << n - 1);
    val += (num << (n - 1)) * (r / num * 2 + c / num);
    FindValue(n - 1, r - num * (r / num), c - num * (c / num));
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> r >> c;
    FindValue(N, r, c);
    cout << val;
    return 0;
}