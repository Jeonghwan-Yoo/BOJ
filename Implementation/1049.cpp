#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int price[2][50];
int good6 = 987654321;
int good1 = 987654321;
int minPrice;

void findGood() {
    for (int i = 0; i < M; ++i) {
        good6 = min(good6, price[0][i]);
    }
    for (int i = 0; i < M; ++i) {
        good1 = min(good1, price[1][i]);
    }
    if (good6 >= good1 * 6) {
        good6 = -1;
    }
}

void pay() {
    int package = N / 6;
    int remainder = N % 6;
    if (good6 != -1) {
        minPrice = package * good6;
        minPrice += remainder * good1;
        int all = (package + 1) * good6;
        minPrice = min(minPrice, all);
    }    
    else {
        minPrice = (package * 6 + remainder) * good1; 
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> price[0][i] >> price[1][i];
    }
    findGood();
    pay();
    cout << minPrice;
    return 0;
}