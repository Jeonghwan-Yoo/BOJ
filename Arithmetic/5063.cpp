#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int r, e, c;
        cin >> r >> e >> c;
        int benefit = e - c;
        if (benefit > r)
            cout << "advertise" << '\n';
        else if (benefit == r)
            cout << "does not matter" << '\n';
        else
            cout << "do not advertise" << '\n';
    }   

    return 0;
}