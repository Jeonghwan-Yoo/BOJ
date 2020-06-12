#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, int> cards;
    int N;
    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        ++cards[num];
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> num;
        cout << cards[num] << ' ';
    }

    return 0;
}