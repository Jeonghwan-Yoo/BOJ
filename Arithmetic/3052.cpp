#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num;
    bool cnt[42] = { false, };
    int distinct = 0;
    for (int i = 0; i < 10; ++i)
    {
        cin >> num;
        int mod = num % 42;
        if (!cnt[mod])
            ++distinct;
        cnt[mod] = true;
    }
    cout << distinct;

    return 0;
}