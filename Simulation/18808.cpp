#include <iostream>

using namespace std;

int N, M, K;
int R, C;
bool board[41][41];

void Rotate(bool (&sticker)[11][11])
{
    int tmpR = C;
    int tmpC = R;
    bool tmp[11][11] = { false, };
    for (int i = 0; i < tmpR; ++i)
        for (int j = 0; j < tmpC; ++j)
            tmp[i][j] = sticker[R - j - 1][i]; 

    R = tmpR;
    C = tmpC;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            sticker[i][j] = tmp[i][j];
}

void Attach(bool (&sticker)[11][11], int r, int c)
{
    for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j)
                if (board[i + r][j + c] == false && sticker[i][j] == true)
                    board[i + r][j + c] = true;
}

bool Find(bool (&sticker)[11][11])
{
    for (int i = 0; i <= N - R; ++i)
    {
        for (int j = 0; j <= M - C; ++j)
        {
            bool check = true;
            for (int r = 0; r < R; ++r)
            {
                for (int c = 0; c < C; ++c)
                {
                    if (sticker[r][c] == true && board[i + r][j + c] == true)
                    {
                        check = false;
                        break;
                    }
                }
                if (check == false)
                    break;
            }
            if (check == true)
            {
                Attach(sticker, i, j);
                return true;
            }
        }
    }
    return false;
}

bool Check(bool (&sticker)[11][11])
{
    bool ret = false;
    for (int i = 0; i < 4; ++i)
    {
        ret = Find(sticker);
        if (ret == true)
            break;
        Rotate(sticker);
    }
    return ret;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    bool sticker[11][11];
    int sum = 0;
    for (int i = 0; i < K; ++i)
    {
        cin >> R >> C;
        int cnt = 0;
        for (int j = 0; j < R; ++j)
        {
            for (int k = 0; k < C; ++k)
            {
                cin >> sticker[j][k];
                if (sticker[j][k] == true)
                    ++cnt;
            }
        }
        if (Check(sticker) == true)
            sum += cnt;
    }    
    cout << sum;

    return 0;
}