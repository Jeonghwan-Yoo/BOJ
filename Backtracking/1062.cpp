#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> words;
int N, K;
int maxReadCnt = 0;

void Read(int n)
{
    int cnt = 0;
    for (int i = 0; i < words.size(); ++i)
    {
        bool check = true;
        for (int j = 0; j < words[i].size(); ++j)
        {
            if (((1 << (words[i][j] - 'a')) & n) == 0)
            {
                check = false;
                break;
            }
        }
        if (check == true)
        {
            ++cnt;
        }
    }
    if (maxReadCnt < cnt)
        maxReadCnt = cnt;
}

void Select(int n, int cnt)
{
    if (cnt == K)
    {
        Read(n);
        return;
    }
    int st = 0;
    int tmp = n ^ (1 << 'a' - 'a') ^ (1 << 'n' - 'a') ^ (1 << 't' - 'a') ^ (1 << 'i' - 'a') ^ (1 << 'c' - 'a');
    while (tmp)
    {
        tmp >>= 1;
        ++st;
    }
    for (int i = st; i < 26; ++i)
    {
        if ((n & (1 << i)) == 0)
        {
            Select(n + (1 << i), cnt + 1);
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        string in;
        cin >> in;
        words.push_back(in);
    }
    if (K >= 5)
    {
        Select((1 << 'a' - 'a') + (1 << 'n' - 'a') + (1 << 't' - 'a') + (1 << 'i' - 'a') + (1 << 'c' - 'a'), 5);
        cout << maxReadCnt;
    }
    else
    {
        cout << 0;
    }

    return 0;
}