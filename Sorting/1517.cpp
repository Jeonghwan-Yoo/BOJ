#include <iostream>
#include <algorithm>

using namespace std;

int A[500'001];
int tmp[500'001];
long long cnt;

void Merge(int ll, int lr, int rl, int rr)
{
    int pos = 0;
    int lpos = ll;
    int rpos = rl;
    int lines = 0;
    while (lpos <= lr && rpos <= rr)
    {
        if (A[lpos] <= A[rpos])
        {
            tmp[pos] = A[lpos];
            ++pos;
            ++lpos;
            cnt += lines;
        }
        else
        {
            tmp[pos] = A[rpos];
            ++pos;
            ++rpos;
            ++lines;
        }
    }
    while (lpos <= lr)
    {
        tmp[pos] = A[lpos];
        ++pos;
        ++lpos;
        cnt += lines;
    }
    while (rpos <= rr)
    {
        tmp[pos] = A[rpos];
        ++pos;
        ++rpos;
        ++lines;
    }
    for (int i = 0; i < pos; ++i)
        A[i + ll] = tmp[i];
}

void MergeSort(int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);
    Merge(l, mid, mid + 1, r);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    MergeSort(0, N - 1);
    for (int i = 0; i < N; ++i)
        cout << A[i] << ' ';
    cout << cnt;
        
    return 0;
}