#include <iostream>
#include <algorithm>

using namespace std;

char ant[51];
bool dir[51];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N1, N2;
    cin >> N1 >> N2;
    for (int i = N1 - 1; i >= 0; --i)
    {
        cin >> ant[i];
        dir[i] = 0;
    }
    for (int i = N1; i < N1 + N2; ++i)
    {
        cin >> ant[i];
        dir[i] = 1;
    }
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t)
    {
        for (int i = 0; i < N1 + N2 - 1; ++i)
        {
            if (dir[i] == 0 && dir[i + 1] == 1)
            {
                swap(ant[i], ant[i + 1]);
                swap(dir[i], dir[i + 1]);
                ++i;
            }
        }
    }    
    cout << ant;    

    return 0;
}