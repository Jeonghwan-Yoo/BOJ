#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K;

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N >> K;
    cout << "<";
    vector<int> people;
    for (int i = 1; i <= N; ++i)
    {
        people.push_back(i);
    }
    int pos = 0;
    for (int i = 0; i < N; ++i)
    {
        pos += K - 1;
        pos %= people.size();
        cout << people[pos];
        if (people.size() - 1> 0)
            cout << ", ";
        people.erase(people.begin() + pos);
    }
    cout << ">";
    return 0;
}