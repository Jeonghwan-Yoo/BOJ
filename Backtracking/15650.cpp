#include <iostream>
#include <numeric>
#include <vector>

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
    vector<int> v(N), sub;
    iota(v.begin(), v.end(), 1);
    Backtracking(0, sub, v);

    return 0;
}