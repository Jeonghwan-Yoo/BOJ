#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int start = 0;
    while (cin >> N)
    {
        ++start;
        vector<pair<string, int> > name;
        name.resize(N);
        string tmp;
        getline(cin, tmp);
        for (int i = 0; i < N; ++i)
        {
            string in;
            getline(cin, in);
            name[i] = { in, 0 };
        }
        for (int i = 0; i < (N << 1) - 1; ++i)
        {
            int num;
            cin >> num;
            char alpha;
            cin >> alpha;
            ++name[num - 1].second;
        }
        for (int i = 0; i < N; ++i)
        {
            if (name[i].second == 1)
            {
                cout << start << ' ' << name[i].first << '\n';
            }
        }
    }
    return 0;
}