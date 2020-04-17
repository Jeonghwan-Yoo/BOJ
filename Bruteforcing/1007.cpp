#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

bool positive[21];
int setX[21];
int setY[21];
int N;

double Matching(int idx, int n)
{
    if ((n << 1) == N)
    {
        double x = 0, y = 0;
        for (int i = 0; i < N; ++i)
        {
            if (positive[i] == true)
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
    ret = min(ret, Matching(idx + 1, n));
    positive[idx] = true;
    ret = min(ret, Matching(idx + 1, n + 1));
    positive[idx] = false;
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cin >> N;
        for (int n = 0; n < N; ++n)
        {
            cin >> setX[n] >> setY[n];
        }
        cout << fixed << setprecision(6) << Matching(0, 0) << '\n';
    }
    return 0;
}