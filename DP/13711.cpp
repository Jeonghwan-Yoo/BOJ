#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int A[100'001];
int B[100'001];
int C[100'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        A[num] = i;
    }
    for (int i = 1; i <= N; ++i)
        cin >> B[i];
    for (int i = 1; i <= N; ++i)
        C[i] = A[B[i]];
        
    vector<int> dp;
    dp.emplace_back(C[1]);
    int cnt = 0;
    for (int i = 2; i <= N; ++i)
    {
        if (dp.back() < C[i])
        {
            dp.emplace_back(C[i]);
            ++cnt;
        }
        else
        {
            auto lb = lower_bound(dp.begin(), dp.end(), C[i]);
            *lb = C[i];
        }
    }
    cout << cnt + 1;

    return 0;
}