#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int adj[101 + 2][101 + 2] = { 0, };
        int dist[101 + 2][101 + 2] = { 0, };
        int n;
        cin >> n;
        vector<pair<int, int> > place(n + 2);
        for (int i = 0; i < n + 2; ++i)
            cin >> place[i].first >> place[i].second;
        for (int i = 0; i < (int)place.size(); ++i)
            for (int j = 0; j < (int)place.size(); ++j)
                if (abs(place[i].first - place[j].first) + abs(place[i].second - place[j].second) <= 50 * 20)
                    adj[i][j] = 1;

        for (int i = 0; i < n + 2; ++i)
            for (int j = 0; j < n + 2; ++j)
                dist[i][j] = adj[i][j];
        
        for (int k = 0; k < n + 2; ++k)
            for (int i = 0; i < n + 2; ++i)
                for (int j = 0; j < n + 2; ++j)
                    if (dist[i][k] == 1 && dist[k][j] == 1)
                        dist[i][j] = 1;

        if (dist[0][n + 1] == 1)
            cout << "happy" << '\n';
        else
            cout << "sad" << '\n';
    }
    
    return 0;
}