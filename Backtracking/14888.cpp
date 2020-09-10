#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_VAL (int)(1e9)
#define MIN_VAL (int)(-1e9)

int N;
int A[12];
int op[4];
int maxVal = MIN_VAL;
int minVal = MAX_VAL;

void Backtracking(int idx, int sum)
{
    if (idx == N)
    {
        maxVal = max(maxVal, sum);
        minVal = min(minVal, sum);
        return;
    }

    if (op[0] > 0)
    {
        --op[0];
        Backtracking(idx + 1, sum + A[idx]);
        ++op[0];
    }
    if (op[1] > 0)
    {
        --op[1];
        Backtracking(idx + 1, sum - A[idx]);
        ++op[1];
    }
    if (op[2] > 0)
    {
        --op[2];
        Backtracking(idx + 1, sum * A[idx]);
        ++op[2];
    }
    if (op[3] > 0)
    {
        --op[3];
        Backtracking(idx + 1, sum / A[idx]);
        ++op[3];
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < 4; ++i)
        cin >> op[i];

    Backtracking(1, A[0]);
    cout << maxVal << '\n' << minVal;

    return 0;
}