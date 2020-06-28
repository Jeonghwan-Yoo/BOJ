#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

enum Category
{
    Common = 0,
    Special = 1,
    Service = 2,
};

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, pair<int, int> > menu;
    int A, B, C;
    cin >> A >> B >> C;
    string name;
    int price;
    for (int i = 0; i < A; ++i)
    {
        cin >> name >> price;
        menu[name] = { Category::Common, price };
    }
    for (int i = 0; i < B; ++i)
    {
        cin >> name >> price;
        menu[name] = { Category::Special, price };
    }
    for (int i = 0; i < C; ++i)
    {
        cin >> name;
        menu[name] = { Category::Service, 1 };
    }
    long long total[3] = { 0ll, };
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> name;
        total[menu[name].first] += menu[name].second;
    }

    bool check = true;
    if (total[Category::Special] > 0 && total[Category::Common] < 20'000)
        check = false;
    if (total[Category::Service] == 1 && total[Category::Special] + total[Category::Common] < 50'000)
        check = false;
    if (total[Category::Service] > 1)
        check = false;

    cout << (check ? "Okay" : "No");

    return 0;
}