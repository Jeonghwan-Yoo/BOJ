#include <iostream>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int N, L;
    cin >> N >> L;
    bool bSuccess = false;
    for (int i = L; i <= 100; ++i) {
        int first = (N / i) - (i >> 1);
        int sum = 0;
        while (sum < N) {
            sum = 0;
            for (int j = 0; j < i; ++j) {
                sum += first + j;
            }
            if (sum == N && first >= 0) {
                for (int j = 0; j < i; ++j) {
                    cout << first + j << ' ';
                }
                bSuccess = true;
                break;
            }
            ++first;
        }
        if (bSuccess == true) {
            break;
        }
    }
    if (bSuccess == false) {
        cout << -1;
    }
    return 0;
}