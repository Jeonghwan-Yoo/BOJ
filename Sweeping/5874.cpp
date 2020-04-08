#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    string in;
    cin >> in;
    int back = 0;
    int sum = 0;
    for (int i = 0; i < in.size() - 1; ++i)
    {
        if (in[i] == in[i + 1] && in[i] == '(')
        {
            ++back;
        }
        else if (in[i] == in[i + 1] && in[i] == ')')
        {
            sum += back;
        }
    }
    cout << sum << '\n';
    return 0;
}