#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<string, set<string> > teamMember;
    unordered_map<string, string> memberTeam;
    int N, M;
    cin >> N >> M;
    string team, member;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> team >> num;
        for (int j = 0; j < num; ++j)
        {
            cin >> member;
            teamMember[team].insert(member);
            memberTeam[member] = team;
        }
    }
    string name;
    int type;
    for (int i = 0; i < M; ++i)
    {
        cin >> name >> type;
        if (type == 0)
            for (auto &s : teamMember[name])
                cout << s << '\n';
        else if (type == 1)
            cout << memberTeam[name] << '\n';
    }

    return 0;
}