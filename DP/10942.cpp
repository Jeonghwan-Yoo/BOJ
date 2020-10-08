#include <iostream>
#include <vector>

using namespace std;

int Check(int s, int e, vector<int> const &seq, vector<vector<int>> &dp)
{
    if (s >= e)
        return 1;

    int &ret = dp[s][e];
    if (ret != -1)
        return ret;
    
    if (seq[s] == seq[e])
        return ret = Check(s + 1, e - 1, seq, dp);
    return 0;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> seq(N + 1);
    for (int i = 1; i <= N; ++i)
        cin>> seq[i];
    
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;
        cout << Check(s, e, seq, dp) << '\n';
    }

    return 0;
}