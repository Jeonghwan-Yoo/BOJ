#include <iostream>
#include <vector>

using namespace std;

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> tree(N);
    for (int i = 0; i < N; ++i)
        cin >> tree[i];
    
    int gcd = tree[1] - tree[0];
    for (int i = 2; i < N; ++i)
        gcd = Gcd(gcd, tree[i] - tree[i - 1]);
    
    cout << (tree[N - 1] - tree[0]) / gcd - N + 1; 

    return 0;
}