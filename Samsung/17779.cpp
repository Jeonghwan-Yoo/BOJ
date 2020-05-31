#include <iostream>
#include <algorithm>

using namespace std;

#define INF 40'000

int N;
int A[21][21];

int Fill(int x, int y, int d1, int d2)
{
    int sum[5] = { 0, };
    int boundary = x + y;
    for (int i = 1; i < x + d1; ++i)
    {
        for (int j = 1; j <= y; ++j)
        {
            if (i + j >= boundary)
                break;
            sum[0] += A[i][j];
        }
    }
    for (int i = x + d1; i <= N; ++i)
    {
        for (int j = 1; j < y - d1 + d2; ++j)
        {
            if (i + j >= boundary)
                break;
            sum[2] += A[i][j];
        }
        boundary += 1 + (i < x + d1 + d2);
    }
    boundary = x + y + d2 + d2;
    for (int i = N; i >= x + d2 + 1; --i)
    {
        for (int j = N; j >= y - d1 + d2; --j)
        {
            if (i + j <= boundary)
                break;
            sum[3] += A[i][j];
        }
    }
    for (int i = x + d2; i >= 1; --i)
    {
        for (int j = N; j > y; --j)
        {
            if (i + j <= boundary)
                break;
            sum[1] += A[i][j];
        }
        boundary -= 1 + (i > x);
    }
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            sum[4] += A[i][j];
    sum[4] -= sum[0] + sum[1] + sum[2] + sum[3];
    sort(sum, sum + 5);

    int diff = sum[4] - sum[0];

    return diff;    
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> A[i][j];

    int diff = INF;
    for (int x = 1; x < N; ++x)
        for (int y = 1; y < N; ++y)
            for (int d1 = 1; y  - d1 >= 1; ++d1)
                for (int d2 = 1; y + d2 <= N && x + d1 + d2 <= N && y + d2 <= N; ++d2)
                    diff = min(diff, Fill(x, y, d1, d2));
    cout << diff;
            
    return 0;
}