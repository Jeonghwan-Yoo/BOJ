#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int que[1'001] = { 0, };
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> que[i];
    
    sort(que, que + N);
    int t = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        t += que[i];
        sum += t;
    }
    cout << sum;
    
    return 0;
}