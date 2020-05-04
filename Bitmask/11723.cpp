#include <iostream>

using namespace std;

#define MAX 20

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M;
    cin >> M;
    int s = 0;
    for (int i = 0; i < M; ++i)
    {
        string in;
        cin >> in;
        switch (in[1])
        {
            // add
            case 'd':
            {
                int x;
                cin >> x;
                s |= (1 << x);
                break;
            }
            // remove
            case 'e':
            {
                int x;
                cin >> x;
                s |= (1 << x);
                s ^= (1 << x);
                break;
            }
            // check
            case 'h':
            {
                int x;
                cin >> x;
                cout << ((s & (1 << x)) > 0 ? 1 : 0) << '\n';
                break;
            }
            // toggle
            case 'o':
            {
                int x;
                cin >> x;
                s ^= (1 << x);
                break;
            }
            // all
            case 'l':
            {
                s = 0x001FFFFF;
                break;
            }
            // empty
            case 'm':
            {
                s = 0;
                break;
            }
        }
    }
    return 0;
}