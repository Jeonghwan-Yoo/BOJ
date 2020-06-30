#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int conv[128];
    conv['A'] = 1;
    conv['C'] = 601;
    conv['G'] = 601 * 601;
    conv['T'] = 601 * 601 * 601;

    int T;
    cin >> T;
    while (T--)
    {
        unordered_map<unsigned long long, int> sub;
        unsigned long long key = 0ll;
        int mcs = 0;
        int k;
        string W;
        cin >> k >> W;
        for (int i = 0; i < k; ++i)
            key += conv[W[i]];
        ++sub[key];
        ++mcs;
        for (int i = k; i < (int)W.size(); ++i)
        {
            key -= conv[W[i - k]];
            key += conv[W[i]];
            ++sub[key];
            if (mcs < sub[key])
                mcs = sub[key];
        }
        cout << mcs << '\n';
    }

    return 0;
}