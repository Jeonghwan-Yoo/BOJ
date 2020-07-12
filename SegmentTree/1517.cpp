#include <iostream>
#include <algorithm>

using namespace std;

int N;
int fenwick[500'001];
int A[500'001];
pair<int, int> B[500'001];

void Update(int k, int x)
{
    while (k <= N)
    {
        fenwick[k] += x;
        k += k & -k;
    }
}

int Query(int k)
{
    int sum = 0;
    while (k >= 1)
    {
        sum += fenwick[k];
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
    {
        cin >> A[i];
        B[i] = { A[i], i };
    }
    sort(B + 1, B + N + 1);

    for (int i = 1; i <= N; ++i)
        A[B[i].second] = i;

    long long cnt = 0ll;
    for (int i = 1; i <= N; ++i)
    {
        Update(A[i], 1);
        cnt += i - Query(A[i]);
    }
    cout << cnt;

    return 0;
}