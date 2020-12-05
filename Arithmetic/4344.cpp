#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << fixed << setprecision(3);
    int C;
    cin >> C;
    while (C--)
    {
        int N;
        cin >> N;
        vector<int> score(N);
        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> score[i];
            sum += score[i];
        }
        double avg = (double)sum / N;
        int cnt = 0;
        for (int i = 0; i < N; ++i)
            if (score[i] > avg)
                ++cnt;

        cout << (double)cnt / N * 100 << "%\n";
    }   

    return 0;
}