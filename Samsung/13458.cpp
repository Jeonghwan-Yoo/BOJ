#include <iostream>

using namespace std;

int N;
int place[1000000];
int pri;
int sub;

int num;

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int tmp;
    for (int i = 0; i < N; ++i) {
       cin >> tmp;
       place[i] = tmp;
    }
    cin >> pri >> sub;
    for (int i = 0; i < N; ++i) {
        ++num;
        place[i] -= pri;
        if (place[i] > 0) {
            num += ((place[i] - 1) / sub + 1);
        }
    }
    cout << num;

    return 0;
}