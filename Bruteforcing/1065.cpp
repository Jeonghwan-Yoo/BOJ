#include <iostream>
#include <string>

using namespace std;

bool Check(int n)
{
    string nToStr = to_string(n);
    int sz = (int)nToStr.size();
    for (int i = 1; i < sz; ++i)
        if (nToStr[1] - nToStr[0] != nToStr[i] - nToStr[i - 1])
            return false;

    return true;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        cnt += Check(i);
    cout << cnt;

    return 0;
}