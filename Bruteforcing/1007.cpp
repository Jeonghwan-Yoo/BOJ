#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int setX[21];
int setY[21];
int N;

double Matching(int positive, int idx, int n)
{
    if ((n << 1) == N)
    {
        double x = 0, y = 0;
        for (int i = 0; i < N; ++i)
        {
            if ((positive & (1 << i)) != 0)
            {
                x += setX[i];
                y += setY[i];
            }
            else
            {
                x -= setX[i];
                y -= setY[i]; 
            }
        }
        double dist = sqrt(x * x + y * y);
        return dist;
    }
    double ret = 987654321;
    if (idx == N)
    {
        return ret;
    }
    ret = min(ret, Matching(positive, idx + 1, n));
    ret = min(ret, Matching(positive ^ (1 << idx), idx + 1, n + 1));

    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N;
        for (int n = 0; n < N; ++n)
        {
            cin >> setX[n] >> setY[n];
        }
        cout << fixed << setprecision(6) << Matching(0, 0, 0) << '\n';
    }
    return 0;
}