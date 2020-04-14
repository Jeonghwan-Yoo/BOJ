#include <iostream>
#include <set>
#include <string>

using namespace std;

string card[10];
int N, K;
set<int> cache;

void Make(int n, int k, string num)
{
    if (k == 0)
    {
        cache.insert(stoi(num));
        return;
    }
    for (int i = 0; i < N; ++i)
    {
        if (((1 << i) & n) != 0)
        {
            n ^= (1 << i);
            Make(n, k - 1, num + card[i]);
            n ^= (1 << i);
        }
    }
}

void Select(int n, int k)
{
    if (k == K)
    {
        Make(n, k, "");
        return;
    }
    int cnt = 0;
    int tmp = n;
    while (tmp)
    {
        tmp >>= 1;
        ++cnt;
    }
    for (int i = cnt; i < N; ++i)
    {
        if (((1 << i) & n) == 0)
            Select(n + (1 << i), k + 1);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> card[i];
    }
    Select(0, 0);
    cout << cache.size();
    return 0;
}