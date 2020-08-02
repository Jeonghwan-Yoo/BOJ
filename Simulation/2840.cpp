#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    bool alpha[26] = { false, };
    stack<pair<int, char> > order;
    int S;
    char A;
    for (int i = 0; i < K; ++i)
    {
        cin >> S >> A;
        order.emplace(S, A);
    }

    vector<char> wheel(N, '?');
    int pos = 0;
    while (!order.empty())
    {
        int s = order.top().first;
        char a = order.top().second;
        order.pop();
        if ((wheel[pos] != '?' || alpha[a - 'A'] == true) && wheel[pos] != a)
        {
            wheel.clear();
            wheel.emplace_back('!');
            break;
        }
        alpha[a - 'A'] = true;
        wheel[pos] = a;
        pos = (pos + s) % N;
    }
    for (int i = 0; i < (int)wheel.size(); ++i)
        cout << wheel[i];

    return 0;
}