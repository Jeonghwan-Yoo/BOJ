#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int constexpr dx[4] = { 0, -1, 0, 1 };
int constexpr dy[4] = { 1, 0, -1, 0 };

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--)
    {
        int minX = 0;
        int minY = 0;
        int maxX = 0;
        int maxY = 0;
        int x = 0, y = 0, d = 0;
        string command;
        cin >> command;
        for (int i = 0; i < (int)command.size(); ++i)
        {
            if (command[i] == 'F')
            {
                x += dx[d];
                y += dy[d];
            }
            else if (command[i] == 'B')
            {
                x -= dx[d];
                y -= dy[d];
            }
            else if (command[i] == 'L')
                d = (d + 3) & 3;
            else if (command[i] == 'R')
                d = (d + 1) & 3;
            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y); 
        }
        cout << (maxY - minY) * (maxX - minX) << '\n';
    }

    return 0;
}