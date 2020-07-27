#include <iostream>
#include <algorithm>

using namespace std;

int Kaprekar(int n)
{
    int cnt = 0;
    int num = n;
    char numToArray[5] = { 0, };
    
    while (num != 6174)
    {
        ++cnt;
        for (int i = 0; i < 4; ++i)
        {
            numToArray[i] = num % 10;
            num /= 10;
        }
        sort(numToArray, numToArray + 4);
        num = 1'000 * numToArray[3] + 100 * numToArray[2] + 10 * numToArray[1] + numToArray[0]
              - (1'000 * numToArray[0] + 100 * numToArray[1] + 10 * numToArray[2] + numToArray[3]);
    }

    return cnt;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    int in;
    while (T--)
    {
        cin >> in;
        cout << Kaprekar(in) << '\n';
    }

    return 0;
}