#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> words;
    for (int i = 0; i < N; ++i)
    {
        string in;
        cin >> in;
        int val = 0;
        for (int j = 0; j < in.size(); ++j)
            val |= (1 << (in[j] - 'a'));
        words.push_back(val);
    }
    if (K >= 5)
    {
        int maxCnt = 0;
        int mask = (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' -'a'));
        for (int i = mask; i < (1 << 26); i = (i + 1) | mask)
        {
            int selected = 0;
            for (int j = 0; j < 26; ++j)
                if ((i & (1 << j)) != 0)
                    ++selected;
            if (selected != K)
                continue;
            int cnt = 0;
            for (int j = 0; j < words.size(); ++j)
                cnt += (words[j] == (words[j] & i));
            if (maxCnt < cnt)
                maxCnt = cnt;
        }
        cout << maxCnt;
    }
    else
    {
        cout << 0;
    }

    return 0;
}