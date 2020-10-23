#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> card(N);
    for (int i = 0; i < N; ++i)
        cin >> card[i];
    
    int blackJack = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                int sum = card[i] + card[j] + card[k];
                if (sum <= M && blackJack < sum)
                    blackJack = sum;
            }
        }
    }
    cout << blackJack;

    return 0;
}