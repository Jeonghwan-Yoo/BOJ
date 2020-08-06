#include <iostream>
#include <algorithm>

using namespace std;

int P[1'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> P[i];

    sort(P, P + N);
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += P[i] * (N - i);
    cout << sum;

    return 0;
}