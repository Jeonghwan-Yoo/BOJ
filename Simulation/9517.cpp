#include <iostream>

using namespace std;

#define BOMB 210
#define PEOPLE 8

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int K, N;
    cin >> K >> N;
    int time = 0;
    int question;
    char answer;
    int cur = K;
    int who = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> question >> answer;
        time += question;
        if (time >= BOMB && who == 0)
            who = cur;
        if (answer == 'T')
            cur = (cur % PEOPLE) + 1;
    }
    cout << who;

    return 0;
}