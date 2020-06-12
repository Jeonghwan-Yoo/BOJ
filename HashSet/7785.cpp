#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    set<string, greater<string> > st;
    int N;
    cin >> N;
    string name, inout;
    for (int i = 0; i < N; ++i)
    {
        cin >> name >> inout;
        if (inout == "enter")
            st.insert(name);
        else if (inout == "leave")
            st.erase(name);
    }
    for (auto &s : st)
        cout << s << '\n';

    return 0;
}