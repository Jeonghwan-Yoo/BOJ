#include <iostream>
#include <iomanip>

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
        int H, W, N;
        cin >> H >> W >> N;
        int story = (N - 1) % H + 1;
        int num = (N - 1) / H + 1;
        cout << story << setw(2) << setfill('0') << num << '\n';
    }

    return 0;
}