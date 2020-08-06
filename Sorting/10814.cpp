#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_AGE 200

vector<string> arr[MAX_AGE + 1];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int age;
    string name;
    for (int i = 0; i < N; ++i)
    {
        cin >> age >> name;
        arr[age].emplace_back(name);
    }
    for (int i = 1; i <= MAX_AGE; ++i)
        for (auto &a : arr[i])
            cout << i << ' ' << a << '\n';

    return 0;
}