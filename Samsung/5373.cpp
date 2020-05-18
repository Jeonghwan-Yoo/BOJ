#include <iostream>
#include <string>

using namespace std;

const char order[7] = "wyrogb";
int faceToInt[26];
const int border[6][12] = {
     { 302, 400, 401, 402, 200, 201, 202, 500, 501, 502, 300, 301 },
     { 220, 422, 421, 420, 322, 321, 320, 522, 521, 520, 222, 221 }, 
     { 20, 402, 412, 422, 100, 101, 102, 520, 510, 500, 22, 21 },
     { 2, 502, 512, 522, 122, 121, 120, 420, 410, 400, 0, 1 },
     { 0, 302, 312, 322, 120, 110, 100, 220, 210, 200, 20, 10 },
     { 22, 202, 212, 222, 102, 112, 122, 320, 310, 300, 2, 12 },
};

void RotateBorder(char (&cube)[6][3][4], int f, char d)
{
    char tmp[12];
    for (int i = 0; i < 12; ++i)
        tmp[i] = cube[border[f][i] / 100][border[f][i] / 10 % 10][border[f][i] % 10];
    if (d == '+')
        for (int i = 0; i < 12; ++i)
            cube[border[f][i] / 100][border[f][i] / 10 % 10][border[f][i] % 10] = tmp[(i + 3) % 12];
    else if (d == '-')
        for (int i = 0; i < 12; ++i)
            cube[border[f][i] / 100][border[f][i] / 10 % 10][border[f][i] % 10] = tmp[(i + 9) % 12];
}

void RotateFace(char (&cube)[6][3][4], int f, char d)
{
    if (d == '+')
    {
        char tmp = cube[f][0][0];
        cube[f][0][0] = cube[f][2][0];
        cube[f][2][0] = cube[f][2][2];
        cube[f][2][2] = cube[f][0][2];
        cube[f][0][2] = tmp;
        tmp = cube[f][0][1];
        cube[f][0][1] = cube[f][1][0];
        cube[f][1][0] = cube[f][2][1];
        cube[f][2][1] = cube[f][1][2];
        cube[f][1][2] = tmp;
    }
    else if (d == '-')
    {
        char tmp = cube[f][0][0];
        cube[f][0][0] = cube[f][0][2];
        cube[f][0][2] = cube[f][2][2];
        cube[f][2][2] = cube[f][2][0];
        cube[f][2][0] = tmp;
        tmp = cube[f][0][1];
        cube[f][0][1] = cube[f][1][2];
        cube[f][1][2] = cube[f][2][1];
        cube[f][2][1] = cube[f][1][0];
        cube[f][1][0] = tmp;
    }
}

void Rotate(char (&cube)[6][3][4], char f, char d)
{
    int face = faceToInt[f - 'A'];
    RotateFace(cube, face, d);
    RotateBorder(cube, face, d);
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    faceToInt['U' - 'A'] = 0;
    faceToInt['D' - 'A'] = 1;
    faceToInt['F' - 'A'] = 2;
    faceToInt['B' - 'A'] = 3;
    faceToInt['L' - 'A'] = 4;
    faceToInt['R' - 'A'] = 5;

    int T;
    cin >> T;
    while (T--)
    {
        char cube[6][3][4];
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    cube[i][j][k] = order[i];
        int N;
        cin >> N;
        while (N--)
        {
            string in;
            cin >> in;
            Rotate(cube, in[0], in[1]);
        }
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
                cout << cube[0][i][j];
            cout << '\n';
        }
    }

    return 0;
}