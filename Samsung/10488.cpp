#include <iostream>
#include <algorithm>

using namespace std;

int A[11];
int N;
int addNum;
int subNum;
int mulNum;
int divNum;
int op[100];

int maxNum = -1e10 - 1;
int minNum = 1e10 + 1;

void cal(int addNum, int subNum, int mulNum, int divNum, int left)
{
    if (left == 0)
    {
        int ret = A[0];
        for (int i = 1; i < N; ++i)
        {
            int curOp = op[i - 1];
            switch (curOp)
            {
                case 0:
                {
                    ret += A[i];
                    break;
                }
                case 1:
                {
                    ret -= A[i];
                    break;
                }
                case 2:
                {
                    ret *= A[i];
                    break;
                }
                case 3:
                {
                    if (ret > 0)
                    {
                        ret /= A[i];
                    }
                    else 
                    {
                        ret *= -1;
                        ret /= A[i];
                        ret *= -1;
                    }
                    break;
                }
            }
        }
        minNum = min(minNum, ret);
        maxNum = max(maxNum, ret);

        return;
    }
    if (addNum > 0)
    {
        op[N - 1 - left] = 0;
        cal(addNum - 1, subNum, mulNum, divNum, left - 1);
    }
    if (subNum > 0)
    {
        op[N - 1 - left] = 1;
        cal(addNum, subNum - 1, mulNum, divNum, left - 1);
    }
    if (mulNum > 0)
    {
        op[N - 1 - left] = 2;
        cal(addNum, subNum, mulNum - 1, divNum, left - 1);
    }
    if (divNum > 0)
    {
        op[N - 1 - left] = 3;
        cal(addNum, subNum, mulNum, divNum - 1, left - 1);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    cin >> addNum >> subNum >> mulNum >> divNum;
    cal(addNum, subNum, mulNum, divNum, addNum + subNum + mulNum + divNum);
    cout << maxNum << '\n' << minNum;

    return 0;
}