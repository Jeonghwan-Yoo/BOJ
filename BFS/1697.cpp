#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    if (N >= K)
        cout << N - K;
    else
    {
        vector<int> visited((K << 1) + 1, -1);
        queue<int> q;
        visited[N] = 0;
        q.emplace(N);
        while (!q.empty())
        {
            int cx = q.front();
            q.pop();

            if (cx == K)
                break;
            
            if (cx - 1 >= 0 && visited[cx - 1] == -1)
            {
                visited[cx - 1] = visited[cx] + 1;
                q.emplace(cx - 1);
            }
            if (cx + 1 <= K && visited[cx + 1] == -1)
            {
                visited[cx + 1] = visited[cx] + 1;
                q.emplace(cx + 1);
            }
            if (cx <= K && visited[cx << 1] == -1)
            {
                visited[cx << 1] = visited[cx] + 1;
                q.emplace(cx << 1);
            }
        }
        cout << visited[K];
    }

    return 0;
}