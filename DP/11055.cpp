#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int A[1'001] = { 0, };
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int dp[1'001] = { 0, };
    int maxVal = 0;
    for (int i = 0; i < N; ++i)
    {
        dp[i] = A[i];
        for (int j = 0; j < i; ++j)
            if (A[j] < A[i] && dp[i] < dp[j] + A[i])
                dp[i] = dp[j] + A[i];
        if (maxVal < dp[i])
            maxVal = dp[i];
    }    
    cout << maxVal << '\n';

    return 0;
}