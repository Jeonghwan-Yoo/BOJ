#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

enum Pic
{
    Cnt = 0,
    Time = 1,
    Student = 2,
    Max = 1000,
};
int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int C;
    cin >> C;
    tuple<int, int, int> pic[21] = { {0, 0, 0}, };
    for (int i = 0; i < C; ++i)
    {
        for (int j = 0; j < N; ++j)
            ++get<Pic::Time>(pic[j]);
        int in;
        cin >> in;
        bool exist = false;
        int minCnt = Pic::Max;
        int maxTime = 0;
        int pos = 0;
        for (int j = 0; j < N; ++j)
        {
            if (get<Pic::Student>(pic[j]) == in)
            {
                ++get<Pic::Cnt>(pic[j]);
                exist = true;
                break;
            }
            else if (get<Pic::Cnt>(pic[j]) <= get<Pic::Cnt>(pic[pos]))
            {
                if (get<Pic::Cnt>(pic[j]) == get<Pic::Cnt>(pic[pos]) && get<Pic::Time>(pic[j]) <= get<Pic::Time>(pic[pos]))
                    continue;
                maxTime = get<Pic::Time>(pic[j]);
                minCnt = get<Pic::Cnt>(pic[j]);
                pos = j;
            }
        }
        if (exist == false)
            pic[pos] = { 1, 0, in };
    }
    sort(pic, pic + N, [&](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
    {
        return get<Pic::Student>(a) < get<Pic::Student>(b);
    });
    for (int i = 0; i < N; ++i)
        cout << get<Pic::Student>(pic[i]) << ' ';
    return 0;
}