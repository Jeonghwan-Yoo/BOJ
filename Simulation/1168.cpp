#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> people;
    for (int i = 1; i <= N; ++i)
        people.emplace_back(i);
    
    cout << "<";
    int pos = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        pos += K - 1;
        if (pos >= (int)people.size())
            pos %= (int)people.size();
        cout << people[pos] << ", ";
        people.erase(people.begin() + pos);
    }
    cout << people[0] << ">";

    return 0;
}