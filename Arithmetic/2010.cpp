#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int total = 0;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        total += num;
    }
    cout << total - N + 1;

    return 0;
}