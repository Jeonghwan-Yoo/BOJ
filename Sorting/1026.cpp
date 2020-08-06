#include <iostream>
#include <algorithm>

using namespace std;

int A[51];
int B[51];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        cin >> B[i];

    sort(A, A + N);
    sort(B, B + N);
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += A[N - i - 1] * B[i];
    cout << sum;

    return 0;
}