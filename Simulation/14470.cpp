#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    
    int time = 0;
    if (A <= 0)
    {
        time += (-A) * C;
        time += D;
        time += B * E;
    }
    else
        time += (B - A) * E;
    
    cout << time;

    return 0;
}