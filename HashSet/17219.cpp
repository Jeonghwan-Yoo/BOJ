#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<string, string> um;
    int N, M;
    cin >> N >> M;
    string cite, pass;
    for (int i = 0; i < N; ++i)
    {
        cin >> cite >> pass;
        um[cite] = pass;
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> cite;
        cout << um[cite] << '\n';
    }

    return 0;
}