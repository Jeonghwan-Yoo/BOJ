#include <iostream>
#include <string>

using namespace std;

int N;

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        bool visited[26] = { 0, };
        string str;
        cin >> str;
        bool success = true;
        char prev;
        for (int j = 0; j < str.size(); ++j)
        {
            if (visited[str[j] - 'a'] == false)
            {
                visited[str[j] - 'a'] = true;
                prev = str[j];
            }
            if (visited[str[j] - 'a'] == true && str[j] != prev)
            {
                success = false;
                break;
            }
        }
        if (success == true)
        {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}