#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    unordered_map<string, int> setName; 
    vector<string> setNum;
    setNum.push_back("");
    for (int i = 1; i <= N; ++i)
    {
        string in;
        cin >> in;
        setName[in] = i;
        setNum.push_back(in);
    }
    for (int i = 0; i < M; ++i)
    {
        string in;
        cin >> in;
        if (isalpha(in[0]))
        {
            cout << setName[in] << '\n';
        }
        else
        {
            cout << setNum[stoi(in)] << '\n';
        }
    }
    return 0;
}