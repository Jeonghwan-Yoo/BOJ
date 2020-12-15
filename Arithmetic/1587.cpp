#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cnt[101] = { 0, };
    int num[5];
    for (int i = 0; i < 5; ++i)
    {
        cin >> num[i];
        ++cnt[num[i]];
    }
    
    int sum = 0;
    for (int i = 0; i < 5; ++i)
        sum += num[i];
    int avg = sum / 5;

    int median;
    int idx = 0;
    for (int i = 0; i <= 100; i += 10)
    {
        idx += cnt[i];
        if (idx > 2)
        {
            median = i;
            break;
        }
    }
    cout << avg << '\n' << median;

    return 0;
}