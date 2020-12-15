#include <iostream>

using namespace std;

int constexpr prizeA[8] = { 0, 5'000'000, 3'000'000, 2'000'000, 500'000, 300'000, 100'000, 0 };
int constexpr numA[7] = { 0, 1, 2, 3, 4, 5, 6 };
int constexpr prizeB[7] = { 0, 5'120'000, 2'560'000, 1'280'000, 640'000, 320'000, 0 };
int constexpr numB[6] = { 0, 1, 2, 4, 8, 16 };

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for (int i = 0; i < 7; ++i)
        {
            a -= numA[i];
            if (a <= 0)
            {
                sum += prizeA[i];
                break;
            }
        }
        for (int i = 0; i < 6; ++i)
        {
            b -= numB[i];
            if (b <= 0)
            {
                sum += prizeB[i];
                break;
            }
        }
        cout << sum << '\n';
    }

    return 0;
}