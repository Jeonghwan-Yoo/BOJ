#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string bin, oct;
    cin >> bin;
    int idx = 0;
    int sz = (int)bin.size();
    int head = sz % 3;
    if (head == 1)
    {
        oct += to_string(bin[0] - '0');
        ++idx;
    }
    else if (head == 2)
    {
        oct += to_string(((bin[0] - '0') << 1) + (bin[1] - '0'));
        idx += 2;
    }
    while (idx < sz)
    {
        oct += to_string(((bin[idx] - '0') << 2) + ((bin[idx + 1] - '0') << 1) + (bin[idx + 2] - '0'));
        idx += 3;
    }
    cout << oct;

    return 0;
}