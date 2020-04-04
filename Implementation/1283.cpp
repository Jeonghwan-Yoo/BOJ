#include <iostream>
#include <string>

using namespace std;

int N;

bool visited[26];

int main() 
{
    freopen("in.txt", "r", stdin);
    cin >> N;
    string tmp;
    getline(cin, tmp);
    for (int i = 0; i < N; ++i)
    {
        string str;
        getline(cin, str);
        int idx = -1;
        for (int j = 0; j < str.size(); ++j)
        {
            if (j == 0 && str[j] != ' ' && visited[tolower(str[j]) - 'a'] == false)
            {
                visited[tolower(str[j]) - 'a'] = true;
                idx = j;
                break;
            }
            if (j != 0 && str[j] != ' ' && str[j - 1] == ' ' && visited[tolower(str[j]) - 'a'] == false)
            {
                visited[tolower(str[j]) - 'a'] = true;
                idx = j;
                break;
            }
        }
        if (idx == -1)
        {
            for (int j = 0; j < str.size(); ++j)
            {
                if (str[j] != ' ' && visited[tolower(str[j]) - 'a'] == false)
                {
                    visited[tolower(str[j]) - 'a'] = true;
                    idx = j;
                    break;
                }
            }
        }
        for (int j = 0; j < str.size(); ++j)
        {
            if (j == idx)
                cout << "[";
            cout << str[j]; 
            if (j == idx)
                cout << "]";
        }
        cout << '\n';
    }
    return 0;
}
