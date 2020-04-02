#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N;
    vector<string> str;
    for (int i = 0; i < N; ++i)
    {
        string tmp;
        cin >> tmp;
        str.push_back(tmp);
    }
    vector<string> stored(N, "");

    for (int i = 0; i < N; ++i)
    {
        stored[i] += str[i][str[i].size() - 1];
    }
    int len = 1;
    while (1)
    {
        bool check = true;
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                if (stored[i] == stored[j])
                {
                    check = false;
                    break;
                }
            }
            if (check == false)
                break;
        }
        if (check == false)
        {
            for (int i = 0; i < N; ++i)
            {
                stored[i] += str[i][str[i].size() - 1 - len];
            }
            ++len;
        }
        else
        {
            cout << len;
            break;
        }
    }

    return 0;
}