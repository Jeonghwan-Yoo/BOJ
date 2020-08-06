#include <iostream>
#include <vector>

using namespace std;

#define MAX_VAL 10'000'000

vector<bool> card;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    card.resize((MAX_VAL << 1) + 1);
    int N;
    cin >> N;
    int in;
    for (int i = 0; i < N; ++i)
    {
        cin >> in;
        card[in + MAX_VAL] = true;
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> in;
        cout << card[in + MAX_VAL] << ' ';
    }

    return 0;
}