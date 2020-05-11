#include <iostream>
#include <string>
#include <queue>

using namespace std;


int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    int arr[300'001] = { 0, };
    for (int i = 0; i < N; ++i)
    {
        string tmp;
        cin >> tmp;
        arr[i] = tmp.size();
    }
    int cnt[21] = { 0, };
    queue<int> q;
    for (int i = 0; i <= K; ++i)
    {
        q.push(arr[i]);
        ++cnt[arr[i]];
    }
    long long pair = 0;
    for (int i = 0; i < N; ++i)
    {
        pair += cnt[q.front()] - 1;
        --cnt[q.front()];
        q.pop();
        if (i + K + 1 < N)
        {
            q.push(arr[i + K + 1]);
            ++cnt[arr[i + K + 1]];
        }
    }
    cout << pair;
    return 0;
}