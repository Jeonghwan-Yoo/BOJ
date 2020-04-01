#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string A, B;
    cin >> A >> B;
    long long sumA = 0;
    long long sumB = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        sumA += A[i] - '0';
    }
    for (int i = 0; i < B.size(); ++i)
    {
        sumB += B[i] - '0';
    }
    cout << sumA * sumB;
    return 0;
}