#include <iostream>
#include <vector>
#include <algorithm>

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

    int prev = -1;
    for (int i = 0; i < N; ++i)
    {
        if (!visited[i] && prev != v[i])
        {
            prev = v[i];
            sub.emplace_back(v[i]);
            visited[i] = 1;
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
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    Backtracking(sub, visited, v);

    return 0;
}