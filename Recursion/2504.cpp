#include <iostream>
#include <string>

using namespace std;

string in;
int idx = 0;
int res = 0;
bool check = true;

void cal(string &st, int mul)
{
    if (idx >= in.size())
    {
        if (st.size() != 0)
            check = false;
        return;
    }
    switch (in[idx])
    {
        case '(':
        {
            string nxt = st + in[idx];
            ++idx;
            cal(nxt, mul * 2);
            return;
        }
        case '[':
        {
            string nxt = st + in[idx];
            ++idx;
            cal(nxt, mul * 3);
            return;
        }
        case ')':
        {
            if (st.back() == '(')
            {
                if (in[idx - 1] == '(')
                {
                    res += mul;
                }
                ++idx;
                if (!st.empty())
                    st.pop_back();
                cal(st, mul / 2);
            }
            else
            {
                check = false;
            }
            return;
        }
        case ']':
        {
            if (st.back() == '[')
            {
                if (in[idx - 1] == '[')
                {
                    res += mul;
                }
                ++idx;
                if (!st.empty())
                    st.pop_back();
                cal(st, mul / 3);
            }
            else
            {
                check = false;
            }
            return;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> in;
    string st;
    while (idx < in.size())
    {
        cal(st, 1);
        ++idx;
    }
    if (check == false)
        res = 0;
    cout << res;

    return 0;
}