#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

void Backtracking(int idx, vector<int> &sub, vector<int> const &v)
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

    sub.emplace_back(v[idx]);
    Backtracking(idx + 1, sub, v);
    sub.pop_back();
    Backtracking(idx + 1, sub, v);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    vector<int> v(N), sub, visited(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    Backtracking(0, sub, v);

    return 0;
}