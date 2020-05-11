#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    queue<int> q;
    for (int i = 1; i <= N; ++i)
        q.push(i);
    string death;
    death += "<";
    while (!q.empty())
    {
        int k = K;
        while (--k)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        death += to_string(q.front()) + ", ";
        q.pop();
    }
    death.pop_back();
    death.pop_back();
    death += ">";
    cout << death;
    
    return 0;
}