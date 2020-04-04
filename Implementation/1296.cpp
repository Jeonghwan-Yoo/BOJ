#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    string man;
    cin >> man;
    int num[4] = { 0, };
    for (int i = 0; i < man.size(); ++i)
    {
        switch (man[i])
        {
            case 'L':
            {
                ++num[0];
                break;
            }
            case 'O':
            {
                ++num[1];
                break;
            }
            case 'V':
            {
                ++num[2];
                break;
            }
            case 'E':
            {
                ++num[3];
                break;
            }
        }
    }
    int N;
    cin >> N;
    string woman;
    int score = -1;
    for (int i = 0; i < N; ++i) 
    {
        int numTmp[4];
        memcpy(numTmp, num, sizeof(num));
        string tmp;
        int tmpScore;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); ++j)
        {
            switch (tmp[j])
            {
                case 'L':
                {
                    ++numTmp[0];
                    break;
                }
                case 'O':
                {
                    ++numTmp[1];
                    break;
                }
                case 'V':
                {
                    ++numTmp[2];
                    break;
                }
                case 'E':
                {
                    ++numTmp[3];
                    break;
                }
            }
        }
        tmpScore = ((numTmp[0] + numTmp[1]) * (numTmp[0] + numTmp[2]) * (numTmp[0] + numTmp[3]) * (numTmp[1] + numTmp[2]) * (numTmp[1] + numTmp[3]) * (numTmp[2] + numTmp[3])) % 100;
        if (tmpScore > score)
        {
            score = tmpScore;
            woman = tmp;
        }
        else if (tmpScore == score)
        {
            if (woman > tmp)
            {
                woman = tmp;
            }
        }
    }
    cout << woman;

    return 0;
}