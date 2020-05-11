#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    queue<int> q;
    for (int i = 0; i < N; ++i)
    {
        string op;
        cin >> op;
        switch (op[1])
        {
            // push
            case 'u':
            {
                int in;
                cin >> in;
                q.push(in);
                break;
            }
            // pop
            case 'o':
            {
                if (!q.empty())
                {
                    cout << q.front() << '\n';
                    q.pop();
                }
                else
                    cout << -1 << '\n';
                break;
            }
            // size
            case 'i':
            {
                cout << q.size() << '\n';
                break;
            }
            // empty
            case 'm':
            {
                cout << q.empty() << '\n'; 
                break;
            }
            // front
            case 'r':
            {
                if (!q.empty())
                    cout << q.front() << '\n';
                else
                    cout << -1 << '\n';
                break;
            }
            // back
            case 'a':
            {
                if (!q.empty())
                    cout << q.back() << '\n';
                else
                    cout << -1 << '\n';
                break;
            }
        }
    }
    return 0;
}