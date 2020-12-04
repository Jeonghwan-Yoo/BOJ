#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        char c;
        cin >> c;
        sum += c - '0';
    }
    cout << sum;

    return 0;
}