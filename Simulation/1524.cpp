#include <iostream>
#include <queue>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        priority_queue<int> jun;
        priority_queue<int> bee;
        for (int i = 0; i < N; ++i)
        {
            int in;
            cin >> in;
            jun.push(in);
        }
        for (int i = 0; i < M; ++i)
        {
            int in;
            cin >> in;
            bee.push(in);
        }
        if (jun.top() >= bee.top())
            cout << "S" << '\n';
        else
            cout << "B" << '\n';
    }
}