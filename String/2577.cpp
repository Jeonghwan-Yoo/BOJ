#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;
    int mul = A * B * C;
    string mulToStr = to_string(mul);
    int sz = (int)mulToStr.size();
    int cnt[10] = { 0, };
    for (int i = 0; i < sz; ++i)
        ++cnt[mulToStr[i] - '0'];
    for (int i = 0; i < 10; ++i)
       cout << cnt[i] << '\n';

    return 0;
}