#include <iostream>
#include <cstring>

using namespace std;

int adj[100'001];
bool visited[100'001];
bool finished[100'001];
int numOfCycle;

void FindCycle(int src)
{
    visited[src] = true;
    int nextSrc = adj[src];
    if (visited[nextSrc] == false)
        FindCycle(nextSrc);
    else if (finished[nextSrc] == false)
    {
        ++numOfCycle;
        for (int i = nextSrc; i != src; i = adj[i])
            ++numOfCycle;
    }
    finished[src] = true;
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
        memset(visited, false, sizeof(visited));
        memset(finished, false, sizeof(finished));
        numOfCycle = 0;
        int N;
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> adj[i];
        for (int i = 1; i <= N; ++i)
            if (visited[i] == false)
                FindCycle(i);
        cout << N - numOfCycle << '\n';
    }
    
    return 0;
}