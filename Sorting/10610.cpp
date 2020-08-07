#include <iostream>

using namespace std;

int cnt[10];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int sum = 0;
    char c;
    while (cin >> c)
    {
        int num = c - '0';
        ++cnt[num];
        sum += num;
    }
    
    if (sum % 3 != 0 || cnt[0] == 0)
        cout << -1;
    else
    {
        for (int i = 9; i >= 0; --i)
            for (int j = 0; j < cnt[i]; ++j)
                cout << i;
    }

    return 0;
}