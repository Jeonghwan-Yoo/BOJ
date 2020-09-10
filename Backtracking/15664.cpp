#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void Backtracking(int idx, int prev, vector<int> &sub, vector<int> const &v)
{
    if (idx - 1 == N)
        return;

    if ((int)sub.size() == M)
    {
        for (int i = 0; i < M; ++i)
            cout << sub[i] << ' ';
        cout << '\n';
        return;
    }

    if (prev != v[idx])
    {
        sub.emplace_back(v[idx]);
        Backtracking(idx + 1, prev, sub, v);
        sub.pop_back();
    }
    Backtracking(idx + 1, v[idx], sub, v);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    vector<int> v(N), sub;
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    Backtracking(0, -1, sub, v);

    return 0;
}