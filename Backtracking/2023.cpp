#include <iostream>

using namespace std;

bool IsPrime(int num)
{
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return false;
    return true;
}

void Backtracking(int num, int cnt)
{
    if (!IsPrime(num))
        return;

    if (cnt == 0)
    {
        cout << num << '\n';
        return;
    }
    
    for (int i = 1; i <= 9; i += 2)
    {
        int nnum = num * 10 + i;
        Backtracking(nnum, cnt - 1);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    --N;
    Backtracking(2, N);
    Backtracking(3, N);
    Backtracking(5, N);
    Backtracking(7, N);
    
    return 0;
}