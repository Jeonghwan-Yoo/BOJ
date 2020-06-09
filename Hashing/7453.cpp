#include <iostream>
#include <vector>

using namespace std;

#define OFFSET (1 << 29)

struct HashTable
{
    vector<pair<int, int> > table;
    HashTable(int n)
    {
        table.resize(n * n * 1.2 + 1);
    }
    void Insert(int num)
    {
        int key = num % (int)table.size();
        int idx = 0;
        while (table[key].second > 0)
        {
            if (table[key].first == num)
            {
                ++table[key].second;
                return;
            }
            ++idx;
            key = (num + idx * idx) % (int)table.size();
        }
        table[key].first = num;
        table[key].second = 1;
    }
    int Find(int num)
    {
        int key = num % (int)table.size();
        int idx = 0;
        while (table[key].second > 0)
        {
            if (table[key].first == num)
                return table[key].second;
            ++idx;
            key = (num + idx * idx) % (int)table.size();
        }
        return 0;
    }
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);
    vector<int> D(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    HashTable hash(N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            hash.Insert(A[i] + B[j] + OFFSET);
    
    long long cnt = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cnt += hash.Find(-C[i] + -D[j] + OFFSET);
    
    cout << cnt;

    return 0;
}