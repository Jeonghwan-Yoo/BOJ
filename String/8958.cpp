#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        string in;
        cin >> in;
        int sz = (int)in.size();
        int sum = 0;
        int cur = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (in[i] == 'X')
                cur = 0;
            else if (in[i] == 'O')
                ++cur;
            sum += cur;
        }
        cout << sum << '\n';
    }

    return 0;
}