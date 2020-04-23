#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    unordered_set<int> setA;
    unordered_set<int> setB;
    cin >> A >> B;
    for (int i = 0; i < A; ++i)
    {
        int num;
        cin >> num;
        setA.insert(num);
    }
    for (int i = 0; i < B; ++i)
    {
        int num;
        cin >> num;
        setB.insert(num);
    }
    int cntA = 0;
    for (auto &s : setA)
    {
        if (setB.find(s) == setB.end())
        {
            ++cntA;
        }
    }
    int cntB = 0;
    for (auto &s : setB)
    {
        if (setA.find(s) == setA.end())
        {
            ++cntB;
        }
    }
    cout << cntA + cntB;
    
    return 0;
}