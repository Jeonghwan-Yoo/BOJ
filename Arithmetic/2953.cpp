#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int maxIdx = 0;
    int maxScore = 0;
    for (int i = 1; i <= 5; ++i)
    {
        int sum = 0;
        int score;
        for (int j = 0; j < 4; ++j)
        {
            cin >> score;
            sum += score;
        }
        if (maxScore < sum)
        {
            maxScore = sum;
            maxIdx = i;
        }
    }
    cout << maxIdx << ' ' << maxScore;

    return 0;
}