#include <iostream>
#include <queue>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; ++i)
        q.emplace(i);
    
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
        q.emplace(q.front());
        q.pop();
    }
    
    return 0;
}