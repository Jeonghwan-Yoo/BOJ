#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<string, string> um;
    int N, P, W, L, G;
    cin >> N >> P >> W >> L >> G;
    string name, score;
    for (int i = 0; i < P; ++i)
    {
        cin >> name >> score;
        um[name] = score;
    }
    int cur = 0;
    bool iron = true;
    while (N--)
    {
        cin >> name;
        if (um.find(name) == um.end() || um[name] == "L")
            cur -= L;
        else if (um[name] == "W")
            cur += W;
        if (cur < 0)
            cur = 0;
        if (cur >= G)
            iron = false;
    }

    cout << "I AM " << (iron == true ? "" : "NOT ") << "IRONMAN!!";    

    return 0;
}