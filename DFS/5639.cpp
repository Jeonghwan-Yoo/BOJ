#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pre;

void Dfs(int left, int right)
{
    if (left >= right)
        return;
    
    int upper = upper_bound(pre.begin() + left + 1, pre.begin() + right, pre[left]) - pre.begin();
    Dfs(left + 1, upper);
    Dfs(upper, right);
    cout << pre[left] << '\n';
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int key;
    while (cin >> key)
        pre.emplace_back(key);
    
    Dfs(0, (int)pre.size());    

    return 0;
}