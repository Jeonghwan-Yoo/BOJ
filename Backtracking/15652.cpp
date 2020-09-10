#include <iostream>
#include <vector>

using namespace std;

int N, M;

void Backtracking(int idx, vector<int> &sub)
{
    if ((int)sub.size() == M)
    {
        for (int i = 0; i < M; ++i)
            cout << sub[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i <= N; ++i)
    {
        sub.emplace_back(i);
        Backtracking(i, sub);
        sub.pop_back();
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    vector<int> sub;
    Backtracking(1, sub);

    return 0;
}