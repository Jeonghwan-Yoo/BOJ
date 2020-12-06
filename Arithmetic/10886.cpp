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
    int isCute;
    for (int i = 0; i < N; ++i)
    {
        cin >> isCute;
        total += isCute;
    }
    if (total > (N >> 1))
        cout << "Junhee is cute!";
    else
        cout << "Junhee is not cute!";

    return 0;
}