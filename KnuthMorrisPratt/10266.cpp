#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 360'000

int fail[MAX];
int ang[MAX << 1];
int ang2[MAX];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int in; 
    for (int i = 0; i < n; ++i)
    {
        cin >> in;
        ang[in] = ang[in + MAX] = true;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> in;
        ang2[in] = true;
    }
    
    for (int i = 1, j = 0; i < MAX; ++i)
    {
        while (j > 0 && ang2[i] != ang2[j])
            j = fail[j - 1];
        if (ang2[i] == ang2[j])
        {
            ++j;
            fail[i] = j;
        }
    }
    bool find = false;
    for (int i = 0, j = 0; i < MAX << 1; ++i)
    {
        while (j > 0 && ang[i] != ang2[j])
            j = fail[j - 1];
        if (ang[i] == ang2[j])
        {
            ++j;
            if (MAX == j)
            {
                find = true;
                break;
            }
        }
    }
    if (find == true)
        cout << "possible";
    else
        cout << "impossible";
 
    return 0;
}