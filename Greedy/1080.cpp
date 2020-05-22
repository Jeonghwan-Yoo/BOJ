#include <iostream>

using namespace std;

void Flip(char (&A)[51][51], int x, int y)
{
    for (int i = y; i < y + 3; ++i)
        for (int j = x; j < x + 3; ++j)
            A[i][j] = ((A[i][j] - '0') ^ 1) + '0'; 
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    char A[51][51] = { 0, };
    char B[51][51] = { 0, };
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> B[i][j];

    int cnt = 0;
    for (int i = 0; i <= N - 3; ++i)
    {
        for (int j = 0; j <= M - 3; ++j)
        {
            if (A[i][j] != B[i][j])
            {
                ++cnt;
                Flip(A, j, i);
            }
        }
    }
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (A[i][j] != B[i][j])
                cnt = -1;
    
    cout << cnt;

    return 0;
}