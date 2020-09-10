#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int N, M;

void Backtracking(vector<int> &sub, vector<int> &visited, vector<int> const &v)
{
    if ((int)sub.size() == M)
    {
        for (int i = 0; i < M; ++i)
            cout << sub[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            sub.emplace_back(v[i]);
            Backtracking(sub, visited, v);
            sub.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    vector<int> v(N), sub, visited(N);
    iota(v.begin(), v.end(), 1);
    Backtracking(sub, visited, v);

    return 0;
}