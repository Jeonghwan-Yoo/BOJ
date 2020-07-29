#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Cog
{
    string arr;
    void Rotate(int dir)
    {
        if (dir == 1)
            arr = arr[7] + arr.substr(0, 7);
        else if (dir == -1)
            arr = arr.substr(1) + arr[0];
    }
};

int T;
Cog cog[1'001];

void Rotate(int loc, int dir)
{
    vector<pair<int, int> > rot;
    rot.emplace_back(loc, dir);
    for (int i = loc + 1; i <= T; ++i)
    {
        if (cog[i].arr[6] == cog[i - 1].arr[2])
            break;
        else
        {
            if (((i - loc) & 1) == 1)
                rot.emplace_back(i, -dir);
            else
                rot.emplace_back(i, dir);
        }
    }
    for (int i = loc - 1; i >= 1; --i)
    {
        if (cog[i].arr[2] == cog[i + 1].arr[6])
            break;
        else
        {
            if (((loc - i) & 1) == 1)
                rot.emplace_back(i, -dir);
            else
                rot.emplace_back(i, dir);
        }
    }

    for (int i = 0; i < (int)rot.size(); ++i)
        cog[rot[i].first].Rotate(rot[i].second);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int i = 1; i <= T; ++i)
        cin >> cog[i].arr;

    int K;
    cin >> K;
    int loc, dir;
    for (int i = 0; i < K; ++i)
    {
        cin >> loc >> dir;
        Rotate(loc, dir);
    }

    int cnt = 0;
    for (int i = 1; i <= T; ++i)
        cnt += cog[i].arr[0] - '0';
    cout << cnt;

    return 0;
}