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
    string in;
    cin >> in;
    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += in[i] - '0';
    cout << sum;

    return 0;
}