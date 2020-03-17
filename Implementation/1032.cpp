#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    string board[50];
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }
    string ans = board[0];
    for (int x = 0; x < ans.size(); ++x) {
        char standard = ans[x];
        for (int y = 0; y < N; ++y) {
            if (standard != board[y][x]) {
                ans[x] = '?';
                break;
            }
        }
    }
    cout << ans;

    return 0;
}