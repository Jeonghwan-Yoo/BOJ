#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T, N, M;
    cin >> T;
    while (T--)
    {
        int S[1'001] = { 0, };
        int A[1'001] = { 0, };
        cin >> N >> M;
        int a, b, p, q;
        for (int i = 0; i < M; ++i)
        {
            cin >> a >> b >> p >> q;
            S[a] += p;
            A[a] += q;
            S[b] += q;
            A[b] += p; 
        }
        double minEx = 1e9;
        double maxEx = 0.0;
        for (int i = 1; i <= N; ++i)
        {
            double ex = 0;
            if (S[i] + A[i] != 0)
                ex = (double)S[i] * S[i] / (S[i] * S[i] + A[i] * A[i]);
            if (minEx > ex)
                minEx = ex;
            if (maxEx < ex)
                maxEx = ex;
        }
        minEx *= 1'000;
        maxEx *= 1'000;
        cout << (int)maxEx << '\n' << (int)minEx << '\n';
    }

    return 0;
}