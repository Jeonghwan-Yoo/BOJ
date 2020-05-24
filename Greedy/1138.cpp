#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int order[10] = { 0, };
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> order[i];

    int que[10] = { 0, };
    for (int num = 1; num <= N; ++num)
    {
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            if (cnt == order[num - 1] && que[i] == 0)
            {
                que[i] = num;
                break;
            }
            else if (que[i] == 0)
                ++cnt;
        }
    }
    for (int i = 0; i < N; ++i)
        cout << que[i] << ' ';
        
    return 0;
}