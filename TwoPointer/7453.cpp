#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> sumAB(N * N);
    vector<int> sumCD(N * N);
    vector<int> a(N);
    vector<int> b(N);
    vector<int> c(N);
    vector<int> d(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    int p = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            sumAB[p] = (a[i] + b[j]);
            sumCD[p] = (c[i] + d[j]);
            ++p;
        }
    sort(sumAB.begin(), sumAB.end());
    sort(sumCD.begin(), sumCD.end());
    int abl = 0;
    int cdr = sumCD.size() - 1;
    long long cnt = 0;
    while (abl < sumAB.size() && cdr >= 0)
    {
        int sum = sumAB[abl] + sumCD[cdr];
        long long cntAB = 1;
        long long cntCD = 1;
        if (sum == 0)
        {
            while (abl + cntAB < sumAB.size() && sumAB[abl] == sumAB[abl + cntAB])
                ++cntAB;
            while (cdr - cntCD >= 0 && sumCD[cdr] == sumCD[cdr - cntCD])
                ++cntCD;
            cnt += cntAB * cntCD;
            abl += cntAB;
            cdr -= cntCD;

        }
        else if (sum > 0)
            --cdr;
        else
            ++abl;
    }
    cout << cnt;
    return 0;
}

// #include <iostream>
// #include <algorithm>

// using namespace std;

// #define MAX 4000

// int sum[MAX * MAX];

// int main()
// {
//     freopen("in.txt", "r", stdin);
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int N;
//     cin >> N;
//     int arr[4][MAX] = { 0, };
//     for (int i = 0; i < N; ++i)
//         cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];
//     int p = 0;
//     for (int i = 0; i < N; ++i)
//         for (int j = 0; j < N; ++j)
//             sum[p++] = arr[0][i] + arr[1][j];
//     sort(sum, sum + p);
//     long long cnt = 0;
//     for (int i = 0; i < N; ++i)
//         for (int j = 0; j < N; ++j)
//         {
//             int minusSum = -(arr[2][i] + arr[3][j]);
//             cnt += upper_bound(sum, sum + p, minusSum) - lower_bound(sum, sum + p, minusSum);
//         }
//     cout << cnt;
//     return 0;
// }
