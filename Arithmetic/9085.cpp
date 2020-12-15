#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int sum = 0;
        int num;
        for (int i = 0; i < N; ++i)
        {
            cin >> num;
            sum += num;
        }
        cout << sum << '\n';
    }

    return 0;
}