#include <iostream>
#include <vector>

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
        int N;
        cin >> N;
        vector<int> v(N);
        int a, b;
        for (int i = 0; i < N; ++i)
        {
            cin >> a >> b;
            v[a - 1] = b;
        }
        int sz = 1;
        int cutline = v[0];
        for (int i = 1; i < (int)v.size(); ++i)
        {
            if (cutline > v[i])
            {
                cutline = v[i];
                ++sz;
            }
        }
        cout << sz << '\n';
    }

    return 0;
}