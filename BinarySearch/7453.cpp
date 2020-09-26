#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);
    vector<int> D(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    
    vector<int> AB;
    vector<int> CD;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            AB.emplace_back(A[i] + B[j]);
            CD.emplace_back(C[i] + D[j]);
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long cnt = 0ll;
    for (int i = 0; i < CD.size(); ++i)
        cnt += upper_bound(AB.begin(), AB.end(), -CD[i]) - lower_bound(AB.begin(), AB.end(), -CD[i]);
    
    cout << cnt;

    return 0;
}