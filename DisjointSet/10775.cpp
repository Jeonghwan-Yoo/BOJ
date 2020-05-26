#include <iostream>

using namespace std;

int parent[100'001];

int Find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int G, P;
    cin >> G >> P;
    for (int i = 1; i <= G; ++i)
        parent[i] = i;
    int cnt = 0;
    for (int i = 0; i < P; ++i)
    {
        int g;
        cin >> g;
        int ret = Find(g);
        if (ret == 0)
            break;
        parent[ret] = ret - 1;
        ++cnt;
    }
    cout << cnt;

    return 0;
}