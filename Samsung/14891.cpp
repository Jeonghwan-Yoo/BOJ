#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Cog
{
    char pole[9];
    void Rotate(int dir)
    {
        if (dir == 1)
        {
            int tmp = pole[7];
            for (int i = 6; i >= 0; --i)
            {
                pole[i + 1] = pole[i];
            }
            pole[0] = tmp;
        }
        else if (dir == -1)
        {
            int tmp = pole[0];
            for (int i = 0; i < 7; ++i)
            {
                pole[i] = pole[i + 1];
            }
            pole[7] = tmp;
        }
    }
};

Cog cog[4];
bool visited[4];

void CheckAndRotate(int num, int dir)
{
    visited[num] = true;
    int left = num - 1;
    bool check = false;
    if (left >= 0 && visited[left] == false && cog[left].pole[2] != cog[num].pole[6])
    {
        CheckAndRotate(left, dir * -1);
    }
    int right = num + 1;
    if (right < 4 && visited[right] == false && cog[right].pole[6] != cog[num].pole[2])
    {
        CheckAndRotate(right, dir * -1);
    }
    cog[num].Rotate(dir);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cin >> cog[i].pole[j];
        }
    }
    int K;
    cin >> K;
    for (int k = 0; k < K; ++k)
    {
        memset(visited, 0, sizeof(visited));
        int num, dir;
        cin >> num >> dir;
        CheckAndRotate(num - 1, dir);
    }
    int res = 0;
    for (int i = 0; i < 4; ++i)
    {
        res += (cog[i].pole[0] - '0') * (1 << i);
    }
    cout << res;
    return 0;
}