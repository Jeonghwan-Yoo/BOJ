#include <iostream>

using namespace std;

int N, M;
int fenwick[100'001 << 1];
int pos[100'001];

void Update(int k, int x)
{
    while (k <= N + M)
    {
        fenwick[k] += x;
        k += k & -k;
    }
}

int Query(int k)
{
    int sum = 0;
    while (k >= 1)
    {
        sum += fenwick[k];
        k -= k & -k;
    }
    return sum;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; ++i)
            pos[i] = 0;
        for (int i = 1; i <= N + M; ++i)
            fenwick[i] = 0;
        for (int i = 1; i <= N; ++i)
        {
            pos[i] = i + M;
            Update(pos[i], 1);
        }
        int choice;
        for (int i = 0; i < M; ++i)
        {
            cin >> choice;
            cout << Query(pos[choice]) - 1 << ' ';
            Update(pos[choice], -1);
            pos[choice] = M - i;
            Update(pos[choice], 1);
        }
        cout << '\n';
    }

    return 0;
}