#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<string, int> um;
    vector<int> visited(N);
    string in;
    for (int i = 0; i < N; ++i)
    {
        cin >> in;
        um[in] = i;
    }

    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> in;
        int num = um[in];
        visited[num] = 1;
        if (num == idx)
        {
            ++idx;
            while (idx < N && visited[idx] == 1)
                ++idx;
        }
        else
            ++cnt;
    }
    cout << cnt;
    
    return 0;
}