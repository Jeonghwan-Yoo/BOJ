#include <iostream>

using namespace std;

char constexpr table[4][5] = {
    { 0, 2, 0, 1 },
    { 2, 1, 3, 0 },
    { 0, 3, 2, 1 },
    { 1, 0, 1, 3 },
};

int charToInt[26];
char intToChar[4];

char DNA[1'000'001];

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    charToInt['A' - 'A'] = 0;
    charToInt['G' - 'A'] = 1;
    charToInt['C' - 'A'] = 2;
    charToInt['T' - 'A'] = 3;
    
    intToChar[0] = 'A';
    intToChar[1] = 'G';
    intToChar[2] = 'C';
    intToChar[3] = 'T';

    int N;
    cin >> N >> DNA;
    
    for (int i = N - 2; i >= 0; --i)
        DNA[i] = intToChar[table[charToInt[DNA[i] - 'A']][charToInt[DNA[i + 1] - 'A']]];
    
    cout << DNA[0];
        
    return 0;
}