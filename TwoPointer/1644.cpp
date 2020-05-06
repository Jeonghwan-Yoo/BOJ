#include <iostream>
#include <vector>

using namespace std;

#define MAX 4000001

vector<int> prime;
int sieve[MAX];

void Eratosthenes(int N)
{
    if (N < 2)
        return;
    prime.push_back(2);
    for (int i = 3; i * i <= N; i += 2)
    {
        if (sieve[i] == 1)
            continue;
        for (int j = i * i; j <= N; j += (i << 1))
            sieve[j] = 1;
    }    
    for (int i = 3; i <= N; i+= 2)
    {
        if (sieve[i] == 0)
            prime.push_back(i);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    Eratosthenes(N);
    int l = 0;
    int r = 0;
    int sz = prime.size();
    int sum = 0;
    int cnt = 0;
    while (r < sz)
    {
        while (sum + prime[r] <= N && r < sz)
        {
            sum += prime[r];
            ++r;
        }
        if (sum == N)
            ++cnt;
        sum -= prime[l];
        ++l;
    }
    cout << cnt;
    return 0;
}