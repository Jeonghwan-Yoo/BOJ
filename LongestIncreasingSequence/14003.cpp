#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[1'000'001];
int sz[1'000'001];
vector<int> dp;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cin >> A[0];
    dp.emplace_back(A[0]);
    int cnt = 0;
    sz[0] = cnt;
    for (int i = 1; i < N; ++i)
    {
        cin >> A[i];
        if (dp.back() < A[i])
        {
            dp.emplace_back(A[i]);
            ++cnt;
            sz[i] = cnt;
        }
        else
        {
            auto lb = lower_bound(dp.begin(), dp.end(), A[i]);
            *lb = A[i];
            sz[i] = lb - dp.begin();
        }
    }

    cout << cnt + 1 << '\n';

    vector<int> lis;
    for (int i = N - 1; i >= 0; --i)
    {
        if (cnt == sz[i])
        {
            --cnt;
            lis.push_back(A[i]);
        }
    }
    for (int i = (int)lis.size() - 1; i >= 0; --i)
        cout << lis[i] << ' ';
    
    return 0;
}