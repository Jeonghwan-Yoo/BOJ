#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int sz = (int)to_string(N).size();
    int num = -1;
    for (int i = N - 9 * sz; i < N; ++i)
    {
        string toStr = to_string(i);
        int sum = i;
        for (int j = 0; j < (int)toStr.size(); ++j)
            sum += toStr[j] - '0';
        if (sum == N)
        {
            num = i;
            break;
        }
    }
    if (num == -1)
        num = 0;
    cout << num;

    return 0;
}