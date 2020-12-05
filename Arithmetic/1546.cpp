#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int score;
    int sum = 0;
    int M = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> score;
        if (M < score)
            M = score;
        sum += score;
    }
    cout << (double)sum / N / M * 100;

    return 0;
}