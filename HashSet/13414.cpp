#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<int, int> um;
    vector<int> v;
    int K, L;
    cin >> K >> L;
    int number;
    for (int i = 0; i < L; ++i)
    {
        cin >> number;
        um[number] = i;
        v.emplace_back(number);
    }
    int cnt = 0;
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (um[v[i]] == i)
        {
            ++cnt;
            cout << setw(8) << setfill('0') << v[i]<< '\n';
            if (cnt >= K)
                break;
        }
    }

    return 0;
}