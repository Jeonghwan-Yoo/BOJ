#include <iostream>
#include <vector>

using namespace std;

#define SZ 6

void Backtracking(int idx, vector<int> &s, vector<int> const &num)
{
    if ((int)s.size() == SZ)
    {
        for (int i = 0; i < SZ; ++i)
            cout << s[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i < (int)num.size(); ++i)
    {
        s.emplace_back(num[i]);
        Backtracking(i + 1, s, num);
        s.pop_back();
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
            
        vector<int> num(k);
        for (int i = 0; i < k; ++i)
            cin >> num[i];

        vector<int> s;
        Backtracking(0, s, num);
        cout << '\n';
    }

    return 0;
}