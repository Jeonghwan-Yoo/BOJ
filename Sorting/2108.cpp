#include <iostream>
#include <cmath>

using namespace std;

#define MAX_VAL 4'000

int cnt[(MAX_VAL << 1) + 1];

int Mean(int n)
{
    long long sum = 0;
    for (int i = 0; i <= (MAX_VAL << 1); ++i)
        sum += i * cnt[i];
    
    return round((double)sum / n);
}

int Median(int n)
{
    int cumulative = 0;
    for (int i = 0; i <= (MAX_VAL << 1); ++i)
    {
        cumulative += cnt[i];
        if (cumulative > (n >> 1))
            return i;
    }

    return -1;    
}

int Frequent(int n)
{
    int posFrequent = 0;
    int maxFrequent = 0;
    int frequent[2] ={ 0, };
    for (int i = 0; i <= (MAX_VAL << 1); ++i)
    {
        if (maxFrequent < cnt[i])
        {
            maxFrequent = cnt[i];
            posFrequent = 0;
            frequent[posFrequent] = i;
        }
        else if (maxFrequent == cnt[i])
        {
            if (posFrequent == 0)
            {
                posFrequent = 1;
                frequent[posFrequent] = i;
            }
        }
    }

    return (frequent[0] < frequent[1] ? frequent[1] : frequent[0]);
}

int Diff(int n)
{
    int minNum;
    int maxNum;
    for (int i = 0; i <= (MAX_VAL << 1); ++i)
    {
        if (cnt[i] != 0)
        {
            minNum = i;
            break;
        }
    }
    
    for (int i = (MAX_VAL << 1); i >= 0; --i)
    {
        if (cnt[i] != 0)
        {
            maxNum = i;
            break;
        }
    }

    return maxNum - minNum;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int in;
    for (int i = 0; i < N; ++i)
    {
        cin >> in;
        ++cnt[in + MAX_VAL];
    }

    cout << Mean(N) - MAX_VAL << '\n';
    cout << Median(N) - MAX_VAL << '\n';
    cout << Frequent(N) - MAX_VAL << '\n';
    cout << Diff(N) << '\n';
    
    return 0;
}