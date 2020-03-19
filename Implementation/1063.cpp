#include <iostream>
#include <string>

using namespace std;

pair<int, int> king;
pair<int, int> stone;

string getIdx[8] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};
const pair<int, int> dir[8] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

void operator+=(pair<int, int> &val1, const pair<int, int> &val2)
{
    val1.first += val2.first;
    val1.second += val2.second;
}
void operator-=(pair<int, int> &val1, const pair<int, int> &val2) 
{
    val1.first -= val2.first;
    val1.second -= val2.second;
}
bool operator==(const pair<int, int> &val1, const pair<int, int> &val2) 
{
    return (val1.first == val2.first && val1.second == val2.second);
}

int main()
{
    freopen("in.txt", "r", stdin);
    string tmpKing, tmpStone;
    cin >> tmpKing >> tmpStone;
    king = make_pair(tmpKing[0] - 'A', tmpKing[1] - '1');
    stone = make_pair(tmpStone[0] - 'A', tmpStone[1] - '1');
    int N;
    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int idx = 0; idx < 8; ++idx)
        {
            if (str == getIdx[idx])
            {
                king += dir[idx];
                if (king.first < 0 || king.first >= 8 || king.second < 0 || king.second >= 8)
                {
                    king -= dir[idx];
                }
                if (king == stone)
                {
                    stone += dir[idx];
                    if (stone.first < 0 || stone.first >= 8 || stone.second < 0 || stone.second >= 8)
                    {
                        stone -= dir[idx];
                        king -= dir[idx];
                    }
                }
            }
        }
    }
    cout << static_cast<char>(king.first + 'A') << static_cast<char>(king.second + '1') << '\n';
    cout << static_cast<char>(stone.first + 'A') << static_cast<char>(stone.second + '1') << '\n';

    return 0;
}