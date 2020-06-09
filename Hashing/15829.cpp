#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define M 1234567891

struct HashTable
{
    vector<pair<int, int> > table;
    int prime;
    HashTable(int n) : prime(31)
    {
        table.resize(n * 1.2 + 1);
    }
    int Function(const string &s)
    {
        long long key = 0;
        long long r = 1;
        for (int i = 0; i < (int)s.size(); ++i)
        {
            key = (key + (s[i] - 'a' + 1) * r) % M;
            r = (r * prime) % M;
        }
        return (int)key;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L;
    cin >> L;
    HashTable hash(L);
    string in;
    cin >> in;
    cout << hash.Function(in);

    return 0;
}