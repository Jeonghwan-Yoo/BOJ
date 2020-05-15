#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int card[500'001] = { 0, };
    for (int i = 0; i < N; ++i)
        cin >> card[i];
    sort(card, card + N);
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int in;
        cin >> in;
        cout << upper_bound(card, card + N, in) - lower_bound(card, card + N, in) << ' ';
    }
    
    return 0;
}