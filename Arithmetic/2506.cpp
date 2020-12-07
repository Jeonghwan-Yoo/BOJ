#include <iostream>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    bool correct;
    int score = 1;
    int total = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> correct;
        if (correct)
        {
            total += score;
            ++score;
        }
        else
            score = 1;
    }   
    cout << total;

    return 0;
}