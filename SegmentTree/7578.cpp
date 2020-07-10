#include <iostream>

using namespace std;

int N;
int A[500'001];
int mp[1'000'001];
int tree[500'001];

void Update(int k, int x)
{
    while (k <= N)
    {
        tree[k] += x;
        k += k & -k;
    }
}

int Sum(int k)
{
    int sum = 0;
    while (k >= 1)
    {
        sum += tree[k];
        k -= k & -k;
    }
    return sum;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> A[i];
    int val;
    for (int i = 1; i <= N; ++i)
    {
        cin >> val;
        mp[val] = i;
    }
    long long intersection = 0ll;
    for (int i = 1; i <= N; ++i)
    {
        Update(mp[A[i]], 1);
        intersection += i - Sum(mp[A[i]]);
    }
    cout << intersection;

    return 0;
}