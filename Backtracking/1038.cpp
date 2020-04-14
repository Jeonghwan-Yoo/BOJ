#include <iostream>

using namespace std;

int N;
long long num;

bool IsDecrese(long long n)
{
    int prev = -1;
    while (n)
    {
        int next = n % 10;
        if (next > prev)
        {
            prev = next;
            n /= 10;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void NextNum(int figure)
{
    int most = 0;
    long long tenth = 1;
    long long replace = 0;
    num /= 10;
    for (int i = 1; i < figure; ++i)
    {
        most += 1;
        tenth *= 10;
        replace += most * tenth;
        num /= 10;
    }
    if (num == 9)
    {
        for (int i = 0; i < 2; ++i)
        {
            most += 1;
            tenth *= 10;
            replace += most * tenth;
        }
        num /= 10;
        num = replace;
    }
    else
    {
        num += 1;
        num *= tenth * 10;
        num += replace;
    }
    if (IsDecrese(num) == false)
    {
        NextNum(figure + 1);
    }
}

void FindN(int n)
{
    if (n >= N)
    {
        return;
    }
    ++num;
    if (num > 9876543210ll)
    {
        num = -1;
        return;
    }
    if (IsDecrese(num) == false)
    {
        NextNum(1);
    }
    FindN(n + 1);
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> N;
    FindN(0);
    cout << num;

    return 0;
}