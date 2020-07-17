#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 5;
    int wood[5];
    for (int i = 0; i < N; ++i)
        cin >> wood[i];
    
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < N - i - 1; ++j)
        {
            if (wood[j] > wood[j + 1])
            {
                int tmp = wood[j];
                wood[j] = wood[j + 1];
                wood[j + 1] = tmp;
                for (int k = 0; k < N; ++k)
                    cout << wood[k] << ' ';
                cout << '\n';
            }
        }
    }
        
    return 0;
}