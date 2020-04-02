#include <iostream>

using namespace std;

int N;
bool status[100];
int num;

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> status[i];
    }
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        int sex;
        cin >> sex;
        int card;
        cin >> card;
        if (sex == 1)
        {
            int cur = card;
            while (cur - 1 < N)
            {
                status[cur - 1] ^= 1;
                cur += card;
            }
        }
        
        else if (sex == 2)
        {
            int curSmall = card;
            int curBig = card;
            status[curSmall - 1] ^= 1;
            --curSmall;
            ++curBig;
            while (curBig - 1 < N && curSmall - 1 >= 0 && status[curSmall - 1] == status[curBig - 1])
            {
                status[curSmall - 1] ^= 1;
                status[curBig - 1] ^= 1;
                --curSmall;
                ++curBig;
            }
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        cout << status[i - 1] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }

    return 0;
}