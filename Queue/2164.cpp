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
        q.push(i);
    while (q.size() > 1)
    {
        q.pop();
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }
    cout << q.front();
    return 0;
}